/*!
 * \file
 */
#include "importgraphdialog.hpp"
#include "ui_importgraphdialog.h"

#include <QFile>
#include <QFileDialog>
#include <QSettings>
#include <QMessageBox>
#include "project.hpp"

namespace Developer {

ImportGraphDialog::ImportGraphDialog(Project *project, QWidget *parent)
    : QDialog(parent)
    , _ui(new Ui::ImportGraphDialog)
    , _project(project)
{
    _ui->setupUi(this);

    // Load the help stylesheet and apply it to this widget
    QFile fp(":/stylesheets/helpdialog.css");
    fp.open(QIODevice::ReadOnly | QIODevice::Text);
    QString style = fp.readAll();
    setStyleSheet(style);
}

ImportGraphDialog::~ImportGraphDialog()
{
    delete _ui;
}

void ImportGraphDialog::selectFile()
{
    QString file = _ui->graphFileEdit->text();
    QFileInfo info(file);

    QSettings settings;
    QString defaultPath = settings.value(
                "Projects/DefaultProjectLocation",
                QVariant(QDir::toNativeSeparators(
                             QDir::homePath()
                             ))
                ).toString();

    QString dir;
    if(info.exists())
        dir = info.dir().path();
    else
        dir = defaultPath;

    file = QFileDialog::getOpenFileName(
                this,
                tr("Import Graph File"),
                dir,
                tr("Graph Files (*.gv *.gxl *.host)"));

    if(!file.isEmpty())
        _ui->graphFileEdit->setText(file);
}

void ImportGraphDialog::accept()
{
    QString path = _ui->graphFileEdit->text();
    QFileInfo info(path);
    if(path.isEmpty() || !info.exists())
    {
        QMessageBox::warning(
                    this,
                    tr("Cannot Import File"),
                    tr("The file provided is invalid or does not exist, cannot "
                       "import the file into the project."));
        return;
    }

    if(_ui->copyCheckBox->isChecked())
    {
        QDir dir = _project->graphsDir();
        QString newPath = dir.filePath(info.fileName());

        int i = 1;
        while(QFile(newPath).exists())
        {
            newPath = dir.filePath(info.baseName() + "_" +
                                   QVariant(i).toString() + "." + info.suffix());
            ++i;
        }

        QFile file(path);
        if(file.copy(newPath))
        {
            _project->addGraph(newPath);
            QDialog::accept();
        }
        else
        {
            QMessageBox::warning(
                        this,
                        tr("Failed to Import File"),
                        tr("GP Developer could not copy the file at '%1' to "
                           "'%2' - unknown error, perhaps a file already exists "
                           "there").arg(path, newPath));
            QDialog::reject();
        }
    }
    else
    {
        _project->addGraph(path);
        QDialog::accept();
    }
}

}
