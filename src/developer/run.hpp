/*!
 * \file
 */
#ifndef RUN_HPP
#define RUN_HPP

#include <QWidget>
#include "../libgp/errors.h"

namespace Ui {
    class Run;
}

namespace Developer {

class Project;
class Graph;
class RunConfig;
class RunConfiguration;

class Run : public QWidget
{
    Q_OBJECT
    
public:
    explicit Run(QWidget *parent = 0);
    ~Run();

    Project *project() const;

    void setProject(Project *proj);

signals:
    void obtainedResultGraph(Graph* resultGraph, RunConfig* runConfig);

public slots:
    RunConfiguration *addRunConfiguration(bool addToProject = true);
    void handleResultGraph(Graph* resultGraph, RunConfig* runConfig);
    
private:
    Ui::Run *_ui;
    Project *_project;
    bool _initial;
};

}

#endif // RUN_HPP
