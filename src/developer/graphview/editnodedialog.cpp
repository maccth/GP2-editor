/*!
 * \file
 */
#include "editnodedialog.hpp"
#include "ui_editnodedialog.h"

#include "nodeitem.hpp"
#include "listvalidator.hpp"

#include <QFile>
#include <QDebug>

namespace Developer {

EditNodeDialog::EditNodeDialog(NodeItem *node, QWidget *parent)
    : QDialog(parent)
    , _ui(new Ui::EditNodeDialog)
    , _node(node)
{
    _ui->setupUi(this);

    // Load the help stylesheet and apply it to this widget
    QFile fp(":/stylesheets/main.css");
    fp.open(QIODevice::ReadOnly | QIODevice::Text);
    QString style = fp.readAll();
    setStyleSheet(style);

    _ui->idEdit->setText(node->id());
    _ui->labelEdit->setText(node->label());
    _ui->rootCheckBox->setChecked(node->isRoot());

    _ui->markComboBox->addItem("none");//set our icon

    QPixmap px(15,15);//create pixmap,size choose yourself, by your taste
    px.fill(QColor(Qt::cyan));//all pixmap will be red
    QIcon icon(px);
    _ui->markComboBox->addItem(icon,"any");//set our icon

    px.fill(QColor(Qt::gray)); //use our pixmap again, but with another color
    icon.addPixmap(px);       //use our icon again
    _ui->markComboBox->addItem(icon,"grey");//set our icon

    px.fill(QColor(Qt::red)); //use our pixmap again, but with another color
    icon.addPixmap(px);       //use our icon again
    _ui->markComboBox->addItem(icon,"red");//set our icon

    px.fill(QColor(Qt::blue));//use our pixmap again, but with another color
    icon.addPixmap(px);       //use our icon again
    _ui->markComboBox->addItem(icon,"blue");

    px.fill(QColor(Qt::green));//use our pixmap again, but with another color
    icon.addPixmap(px);        //use our icon again
    _ui->markComboBox->addItem(icon,"green");

    int currentMarkIndex = _ui->markComboBox->findText(_node->mark());
    if (currentMarkIndex != -1)
        _ui->markComboBox->setCurrentIndex(currentMarkIndex);

    _labelValidator = new ListValidator(this);
    _ui->labelEdit->setValidator(_labelValidator);
}

EditNodeDialog::~EditNodeDialog()
{
    delete _ui;
    delete _labelValidator;
}

void EditNodeDialog::accept()
{
    _node->setId(_ui->idEdit->text());
    _node->setLabel(_ui->labelEdit->text());

    //qDebug() << "Node Label is: " << _ui->labelEdit->text();
    _node->setIsRoot(_ui->rootCheckBox->isChecked());
    //_node->setMarked(_ui->markedCheckBox->isChecked());
    _node->setMark(_ui->markComboBox->currentText());

    QDialog::accept();
}

}
