/*!
 * \file
 */
#ifndef RUNCONFIGURATION_HPP
#define RUNCONFIGURATION_HPP

#include <QWidget>

namespace Ui {
    class RunConfiguration;
}

namespace Developer {

class Project;
class Rule;
class RunConfig;

class RunConfiguration : public QWidget
{
    Q_OBJECT
    
public:
    explicit RunConfiguration(Project *proj, QWidget *parent = 0);
    ~RunConfiguration();

		RunConfig *getRunConfig();

public slots:
    void toggleDetails();

    void updatePrograms();
    void updateGraphs();
    void runConfiguration();
    
private:
    Ui::RunConfiguration *_ui;
    Project *_project;
		RunConfig *_config;
    void run(QString program, QString graph, QString output);
		int call(QString cmd);
    QString rulesToQString(QVector<Rule *> rules);

    int _runs;
};

}

#endif // RUNCONFIGURATION_HPP
