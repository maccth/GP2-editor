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
    qDebug() << "Running configuration";

	  /* Location of selected GP program */ 
	  QString program;
	  //program = "~/github/GP2Test/programs/1.gpp";

	  QString configName =  _ui->configurationNameEdit->text();
	  qDebug() << qPrintable(configName);

	  QString progName = _ui->programCombo->currentText();
	  Program* prog = _project->program(progName);
    QString programString = prog->program();
	  //program = qPrintable(prog->absolutePath());


    // Collect all rule specifications, we have to append them to the program text
    QVector<Rule *> rules =  _project->rules();
    QString ruleStrings = rulesToQString(rules);

    // Create temporary file to hold program text and rules
    QString programTmp = prog->absolutePath();
    programTmp += ".tmp";     
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

	  /* Location of selected GP host graph */ 
	  QString hostgraph;

	  QString graphName = _ui->targetGraphCombo->currentText();
	  Graph* graph = _project->graph(graphName);
	  hostgraph = graph->absolutePath();


    /* Location of output */
    QDir resultsDir = _project->resultsDir(); 
    QString results = resultsDir.absolutePath();

    qDebug() << "Results dir is: " << results << ", exists: " <<  resultsDir.exists() << ", isReadable: " << resultsDir.isReadable();

    QString output = results + "/" + configName + + "_run" + QVariant(_runs).toString() + ".gpg"; //eg. project/results/RunConfig1_run1.gpg  or project/results/RunConfig1_run2.gpg etc.
    QFileInfo checkFile(output);
    if (checkFile.exists())
    {
        qDebug() << "Truncating the file: " << output;
        QFile outputGraph(output);
        outputGraph.open(QFile::WriteOnly|QFile::Truncate);
        outputGraph.close();
    }

	  //hostgraph = "~/github/GP2Test/hostgraphs/1.graph";

	  // Update the corresponding RunConfig object 
	  _config->setName(configName);
	  _config->setProgram(prog->name());
	  _config->setGraph(graph->fileName());
	
	  /* Call the compiler and run the executable */
	  run (programTmp, hostgraph, output);
    
    qDebug() << "Attempting to open output graph."; 
    Graph* resultGraph = new Graph(output, this);
    emit obtainedResultGraph(resultGraph, _config);
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


void RunConfiguration::run(QString program, QString graph, QString output)
{
	  /* Location of GP Compiler */
	  //QString GPCompilerDir = "~/github/GP2/Compiler";
	  QString GPCompilerDir = QString(COMPILER_LOCATION);

    //qDebug() << "Location of GP2 Compiler: " << GPCompilerDir;// << " " << QString(COMPILER_LOCATION);

	  /* Create command for compiling program and host graph */
	  QString CompileCmd = QString();


    CompileCmd += "cd " + GPCompilerDir + "/src";
    CompileCmd += " && " ;
    CompileCmd += GPCompilerDir + "/src/GP2-compile ";
    CompileCmd += "-o " + output + " ";
    CompileCmd += program + " " + graph;

    /*asprintf(&CompileCmd, "cd %s && %s/GP2-compile %s %s " , 
				  GPCompilerDir, 
				  GPCompilerDir, 
				  program, 
				  graph );*/
	  if (call(CompileCmd) !=0) return;
    _runs ++;

	  /* Create command for running the GP program on the host graph */
	  QString RunCmd = QString();
    RunCmd += "cd " + GPCompilerDir + "/runtime";
    RunCmd += " && make && ";
    RunCmd += GPCompilerDir + "/runtime/GP2-run";

	  /*asprintf(&RunCmd, "cd %s && %s/../runtime/GP2-run", 
				  GPCompilerDir, 
				  GPCompilerDir);*/

	  call(RunCmd);
}

// Return 1 -- error during execution
// Return 0 -- all fine
int RunConfiguration::call(QString cmd)
{
	  // The mechanism for calling the GP compiler must be available
	  //qDebug() << "Checking if command processor is available...";
	  if (system(NULL))  ;//qDebug() << "Ok";
	  else 
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

    qDebug() << "  Command is: ";
    qDebug() << QString(command);

	  fp = popen(command, "r");
	  char path[1035]; // output line

	  if (fp == NULL)
	  {
				  qDebug() << "Failed to run %s." << cmd;
				  return 1; 
	  }

	  /* Read the output a line at a time and output it */
	  qDebug() << "GP2 Pipeline output:";
	  while (fgets(path, sizeof(path)-1, fp) != NULL) {
		  qDebug() << path;
	  }

	  /* close stream */
	  pclose(fp);
	  return 0;
}


}
