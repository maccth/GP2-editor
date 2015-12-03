/*!
 * \file
 */
#include "runconfiguration.hpp"
#include "ui_runconfiguration.h"

#include "project.hpp"
#include "rule.hpp"

#include <QFile>
#include <QByteArray>
#include <QFileInfo>
#include <QFile>
#include <QMessageBox>
#include <QProcess>

#include <stdlib.h>  /* system, NULL, EXIT_FAILURE */

//#ifndef COMPILER_LOCATION
//  #define COMPILER_LOCATION @COMPILER_LOCATION@
//#endif

namespace Developer {

class Rule;

RunConfiguration::RunConfiguration(Project *proj, QWidget *parent)
    : QWidget(parent)
    , _ui(new Ui::RunConfiguration)
    , _project(proj)
    , _runs(0)
{
    _ui->setupUi(this);

    // Load the main stylesheet and apply it to this widget
    QFile fp(":/stylesheets/runconfiguration.css");
    fp.open(QIODevice::ReadOnly | QIODevice::Text);
    QString style = fp.readAll();
    setStyleSheet(style);

    _ui->detailsWidget->setVisible(false);

		_config = new RunConfig(proj);

    updatePrograms();
    updateGraphs();
}

RunConfiguration::~RunConfiguration()
{
    delete _ui;

		_project->removeConfig(_config);
		delete _config;
}

RunConfig *RunConfiguration::getRunConfig()
{
		return _config;
}

void RunConfiguration::toggleDetails()
{
    _ui->detailsWidget->setVisible(!_ui->detailsWidget->isVisible());

    if(_ui->detailsWidget->isVisible())
        _ui->arrowImage->setPixmap(QPixmap(":/icons/bullet_arrow_down.png"));
    else
        _ui->arrowImage->setPixmap(QPixmap(":/icons/bullet_arrow_right.png"));
}

void RunConfiguration::updatePrograms()
{
    _ui->programCombo->clear();
    QVector<Program *> programs = _project->programs();
    for(QVector<Program *>::iterator iter = programs.begin();
        iter != programs.end(); ++iter)
    {
        Program *prog = *iter;
        if(prog == 0)
        {
            qDebug() << "Null pointer in RunConfiguration::updatePrograms(), "
                        "ignoring.";
        }
        _ui->programCombo->addItem(prog->name());
    }
}

void RunConfiguration::updateGraphs()
{
    _ui->targetGraphCombo->clear();
    QVector<Graph *> graphs = _project->graphs();
    for(QVector<Graph *>::iterator iter = graphs.begin();
        iter != graphs.end(); ++iter)
    {
        Graph *graph = *iter;
        if(graph == 0)
        {
            qDebug() << "Null pointer in RunConfiguration::updateGraphs(), "
                        "ignoring.";
        }
        _ui->targetGraphCombo->addItem(graph->fileName());
    }
}

void RunConfiguration::runConfiguration()
{

    QString configName =  _ui->configurationNameEdit->text();
    qDebug() << "Running configuration" << configName;

    QString progName = _ui->programCombo->currentText();
    Program* prog = _project->program(progName);    // exploiting that project->program(path) first iterates through _programs and compares program.name() with path
    QString programString = prog->program();
    //program = qPrintable(prog->absolutePath());

    // Collect all rule specifications, we have to append them to the program text
    QVector<Rule *> rules =  _project->rules();
    QString ruleStrings = rulesToQString(rules);

    // Create temporary file to hold program text and rules
    QString programTmp = prog->absolutePath();
    programTmp += ".gp2";
    QFile file(programTmp);  
  
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) 
    {
        qDebug() << "Could not open a temporary file for writing: " << programTmp;
    }
    else 
    {
        QTextStream content(&file);
        content << programString << "\n\n" << ruleStrings;
    }
    file.close();

    /* Location of selected GP host graph */
    QString hostgraphFile;

    QString graphName = _ui->targetGraphCombo->currentText();
    Graph* graph = _project->graph(graphName);
    hostgraphFile = graph->absolutePath();


    /* Desired location of output */
    // The actual output is put by default in /tmp/gp2/gp2.output
    QDir resultsDir = _project->resultsDir(); 
    QString results = resultsDir.absolutePath();

    //qDebug() << "Results dir is: " << results << ", exists: " <<  resultsDir.exists() << ", isReadable: " << resultsDir.isReadable();

    QString output = results + "/Graph"+ QVariant(_runs).toString() + "_" + configName + ".host"; //eg. project/results/RunConfig1_run1.gpg  or project/results/RunConfig1_run2.gpg etc.
    QFileInfo checkFile(output);
    if (checkFile.exists())
    {
        qDebug() << "Truncating the file: " << output;
        QFile outputFile(output);
        outputFile.open(QFile::WriteOnly|QFile::Truncate);
        outputFile.close();
    }

    //hostgraph = "~/github/GP2Test/hostgraphs/1.graph";

    // Update the corresponding RunConfig object
    _config->setName(configName);
    _config->setProgram(prog->name());
    _config->setGraph(graph->fileName());
    //_config->save();

    /* Call the compiler and run the executable */
    bool success = run(programTmp, hostgraphFile, output);
    if (!success)
    {
        // The Compiler failed to validate/compile/execute (instead of giving a proper Fail)
        return;
    }
    _runs ++;

    /*
      Check for failure - represented as a string in the output
      The compiler uses the following code to represent failure:
        fprintf(output_file, \"No output graph: rule %s not applicable.\\n\")
        fprintf(output_file, \"No output graph: Fail statement invoked\\n\")
    */
    bool failure = false;

    QFile result(output);
    // Attempt to open the output file for reading
    if (!result.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "  " << "Could not open result file for reading: " << output;
        return;
    }
    else
    {
        // Create input text stream for reading the file contents
        QTextStream data(&result);
        if (!data.atEnd())
        {
            // Read first line of output
            QString line = data.readLine();

            // Compare with failure string
            failure = line.startsWith("No output graph");
            if (failure)
            {
                qDebug() << "  Failure detected: " << output;
            }
        }
    }

    result.close();

    if (failure)
    {
        QMessageBox::information(
                    this,
                    tr("Run Failed"),
                    tr("Running the program produced Failure"));
        return;
    }

    qDebug() << "Attempting to open output graph.";

    //Graph* resultGraph = new Graph(output, this);
    emit obtainedResultGraph(output, _config);
}

QString RunConfiguration::rulesToQString(QVector<Rule *> rules)
{
    QStringList resultList;

    for (QVector<Rule *>::iterator it = rules.begin(); it!= rules.end(); ++it)
    {
        Rule* rule = *it;
        resultList << rule->toAlternative();
    }

    return resultList.join("\n");
}


bool RunConfiguration::run(QString programFile, QString graphFile, QString outputFile)
{
    /* Location of GP Compiler */
    //QString GPCompilerDir = "~/github/GP2/Compiler";
    QString GPCompilerDir = QString(COMPILER_LOCATION);
    QString Compiler = GPCompilerDir + "/GP2-compile";
    QStringList args = QStringList();

    //qDebug() << "Location of GP2 Compiler: " << Compiler;

    /* ******************************* */
    /* Validate program and host graph */
    /* ******************************* */
    args << "-p" << programFile;   // start with validating the program

    QProcess validate;
    // http://stackoverflow.com/questions/3852587/how-to-get-stdout-from-a-qprocess
    validate.setProcessChannelMode(QProcess::MergedChannels);

    validate.start(Compiler, args);
    qDebug () << "  Attempting to Validate program:" << Compiler << args;

    if (!validate.waitForStarted())
    {
        QMessageBox::information(
                    this,
                    tr("Validation Failed"),
                    tr("Could not start validating the given program/rules."));
        validate.close();
        return false;
    }

    if (!validate.waitForFinished()) // sets current thread to sleep
    {
        QMessageBox::information(
                    this,
                    tr("Validation Failed"),
                    tr("Could not finish validating the given program/rules."));
        validate.close();
        return false;
    }

    QByteArray validateOutput = validate.readAllStandardOutput();
    qDebug() << "    " << QString(validateOutput).simplified();
    if (!validateOutput.contains("is valid"))
    {
        QMessageBox::information(
                    this,
                    tr("Validation Failed"),
                    tr("Could not validate the given configartion. See the log for details."));
        validate.close();
        return false;
    }
    validate.close();

    // do the same for the host graph
    args.clear(); args << "-h" << graphFile;
    validate.start(Compiler, args);
    qDebug () << "  Attempting to Validate host graph:" << Compiler << args;

    if (!validate.waitForStarted())
    {
        QMessageBox::information(
                    this,
                    tr("Validation Failed"),
                    tr("Could not start validating the given host graph."));
        validate.close();
        return false;
    }

    if (!validate.waitForFinished())
    {
        QMessageBox::information(
                    this,
                    tr("Validation Failed"),
                    tr("Could not finish validating the given host graph."));
        validate.close();
        return false;
    }

    validateOutput = validate.readAllStandardOutput();
    qDebug() << "    " << QString(validateOutput).simplified();
    if (!validateOutput.contains("is valid"))
    {
        QMessageBox::information(
                    this,
                    tr("Validation Failed"),
                    tr("Could not validate the given host graph. See the log for details."));
        validate.close();
        return false;
    }
    validate.close();

    /* *************************************************** */
    /* Create command for compiling program and host graph */
    /* *************************************************** */
    args.clear();
    args << programFile << graphFile;

    // The actual output is put by default in /tmp/gp2/gp2.output
    QProcess compile;
    // http://stackoverflow.com/questions/3852587/how-to-get-stdout-from-a-qprocess
    compile.setProcessChannelMode(QProcess::MergedChannels);

    qDebug () << "  Attempting to Compile configuration:" << Compiler << args;
    compile.start(Compiler, args);
    if (!compile.waitForStarted())
    {
        QMessageBox::information(
                    this,
                    tr("Compilation Failed"),
                    tr("Could not start compiling the given configartion."));
        compile.close();
        return false;
    }

    if (!compile.waitForFinished())
    {
        QMessageBox::information(
                    this,
                    tr("Compilation Failed"),
                    tr("Could not finish compiling the given configartion."));
        compile.close();
        return false;
    }

    QByteArray compileOutput = compile.readAllStandardOutput();
    qDebug() << "    " << QString(compileOutput).simplified();
    if (!compileOutput.contains("Generating program code..."))
    {
        QMessageBox::information(
                    this,
                    tr("Compilation Failed"),
                    tr("Could not compile the given configartion. See the log for details."));
        compile.close();
        return false;
    }
    compile.close();

    /* Create command for running the GP program on the host graph */
    QString RunCmd = QString();
    RunCmd += "cd /tmp/gp2";
    RunCmd += " && make && ";
    RunCmd += "./GP2-run && cp gp2.output " + outputFile;

    qDebug () << "  Attempting to Execute program.";

    return (call(RunCmd) == 0 );
}

// Return 1 -- error during execution
// Return 0 -- all fine
int RunConfiguration::call(QString cmd)
{
    // The mechanism for calling the GP compiler must be available
    //qDebug() << "Checking if command processor is available...";
    if (!system(NULL)) //qDebug() << "Ok";
    {
        qDebug() << "Command processor is not available;"
                      "stopping." ;
        return 1;
    }

    // printf ("Executing command...\n");

    // file stream
    FILE *fp; 
	
    /* Open the command for reading */
    QByteArray ba = cmd.toLatin1();
    const char* command = ba.data();

    qDebug() << "  " << "Command is: ";
    qDebug() << "  " << QString(command);

    fp = popen(command, "r");
    char path[1035]; // output line

    if (fp == NULL)
    {
        qDebug() << "  " << "Failed to run %s." << cmd;
        return 1;
    }

    /* Read the output a line at a time and output it */
    qDebug() << "  " << "=== GP2 Pipeline output ===";
    while (fgets(path, sizeof(path)-1, fp) != NULL)
        qDebug() << "  " << path;

    /* close stream */
    qDebug() << "  " << "===========================";
    qDebug() << "";
    pclose(fp);
    return 0;
}


}
