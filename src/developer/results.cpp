/*!
 * \file
 */
#include "results.hpp"
#include "ui_results.h"

#include "helpdialog.hpp"
#include "project.hpp"

namespace Developer {

Results::Results(QWidget *parent)
    : QWidget(parent)
    , _ui(new Ui::Results)
{
    _ui->setupUi(this);


    QStringList items;
    items << "Results";
    QTreeWidgetItem *root = new QTreeWidgetItem(items);
    root->setIcon(0, QIcon(QPixmap(":/icons/application-icon.png")));
    _ui->resultsTreeWidget->addTopLevelItem(root);
}

Results::~Results()
{
    delete _ui;
}

void Results::setProject(Project *project)
{
    if(project == 0)
    {
        qDebug() << "Results::setProject() handed a null pointer... not pleased";
        return;
    }

    _project = project;
    _currentFile = 0;

		/* Set up run configurations
		if(_project->runConfigurations().count() > 0)
		{
			RunConfig *config = _project->runConfigurations().at(0);
			_ui->results->setConfig(config);
      if(_ui->stackedWidget->currentIndex() == 0)
      {
          _project->setCurrentFile(config->absolutePath(), Project::RuleFile);
          _currentConfig = config;
      }


		}*/

    connect(_project, SIGNAL(graphListChanged()), this, SLOT(graphListChanged()));
    connect(_project, SIGNAL(graphStatusChanged(QString,int)),
            this, SLOT(graphStatusChanged(QString,int))
            );
    graphListChanged();
}

void Results::graphClicked(QTreeWidgetItem *item)
{
    QTreeWidgetItem *parent = item->parent();
    if(parent == 0)
        return;

    // Handle a clicked result
		//RunConfig* config = _project->runConfig(item->text(0));
		{

		}

}

void Results::graphListChanged()
{

}

void Results::graphStatusChanged(QString path, int status)
{

}

void Results::handleGraphHasFocus(GraphWidget *graphWidget)
{
    emit graphHasFocus(graphWidget);
}

void Results::handleGraphLostFocus(GraphWidget *graphWidget)
{
    emit graphLostFocus(graphWidget);
}

}
