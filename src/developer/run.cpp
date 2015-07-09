/*!
 * \file
 */
#include "run.hpp"
#include "ui_run.h"

#include "project.hpp"
#include "runconfiguration.hpp"

namespace Ui {
    class RunConfiguration;
}

namespace Developer {

Run::Run(QWidget *parent)
    : QWidget(parent)
    , _ui(new Ui::Run)
    , _initial(true)
{
    _ui->setupUi(this);
}

Run::~Run()
{
    delete _ui;
}

Project *Run::project() const
{
    return _project;
}

void Run::setProject(Project *proj)
{
    if(proj == 0)
    {
        qDebug() << "Run::setProject() handed null pointer, ignoring";
        return;
    }

    _project = proj;

    QLayoutItem *item;
    while((item = _ui->runConfigurations->layout()->takeAt(0)) != 0)
    {
        delete item->widget();
        delete item;
    }

    QVector<RunConfig *> runConfigs = _project->runConfigurations();
    if(runConfigs.size() < 1)
    {
        _initial = true;
        QLabel *label = new QLabel(tr("There are currently no run "
                                      "configurations set, click the button "
                                      "below to add one"),
                                   _ui->runConfigurations);
        _ui->runConfigurations->layout()->addWidget(label);
    }
    else
    {
        // Populate with run configurations
    }
    _ui->addRunConfigurationButton->setEnabled(true);
}

void Run::handleResultGraph(Graph* resultGraph, RunConfig* runConfig)
{
    emit obtainedResultGraph(resultGraph, runConfig);
}


RunConfiguration *Run::addRunConfiguration(bool addToProject)
{
    if(_initial)
    {
        _initial = false;

        QLayoutItem *item;
        while((item = _ui->runConfigurations->layout()->takeAt(0)) != 0)
        {
            delete item->widget();
            delete item;
        }
    }

    RunConfiguration *runConfiguration = new RunConfiguration(_project, _ui->runConfigurations);
    _ui->runConfigurations->layout()->addWidget(runConfiguration);

    if(addToProject)
    {
        // Add the run configuration to the project
				RunConfig *runConfig = runConfiguration->getRunConfig();
				_project->addRunConfig(runConfig);
    }

    connect (runConfiguration, SIGNAL(obtainedResultGraph(Graph*, RunConfig*)), this, SLOT(handleResultGraph(Graph*, RunConfig*))  );

    return runConfiguration;
}

}
