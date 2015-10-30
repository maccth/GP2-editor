/*!
 * \file
 */
#include "editedgedialog.hpp"
#include "ui_editedgedialog.h"

#include "graphview/edgeitem.hpp"
#include "listvalidator.hpp"
#include "edge.hpp"
#include "graph.hpp"

#include <QFile>
#include <QDebug>

namespace Developer {

EditEdgeDialog::EditEdgeDialog(EdgeItem *edgeItem, QWidget *parent)
    : QDialog(parent)
    , _ui(new Ui::EditEdgeDialog)
    , _edge(edgeItem)
{
    _ui->setupUi(this);

    // Load the help stylesheet and apply it to this widget
    QFile fp(":/stylesheets/main.css");
    fp.open(QIODevice::ReadOnly | QIODevice::Text);
    QString style = fp.readAll();
    setStyleSheet(style);

    //QStringList nodes = _edge->edge()->parent()->nodeIdentifiers();

    _ui->idEdit->setText(_edge->id());
    _ui->idEdit->setReadOnly(true);

    _ui->labelEdit->setText(_edge->label());

    qDebug() << _edge->isBidirectional();
    _ui->bidirectionalBox->setChecked(_edge->isBidirectional());

    //_ui->fromComboBox->addItems(nodes);
    //_ui->toComboBox->addItems(nodes);

    _ui->fromNode->setText(_edge->from()->id());
    //_ui->fromComboBox->setCurrentIndex(
    //            _ui->fromComboBox->findText(_edge->from()->id())
    //            );
    _ui->toNode->setText(_edge->to()->id());
    //_ui->toComboBox->setCurrentIndex(
    //            _ui->fromComboBox->findText(_edge->to()->id())
    //            );


    _ui->markComboBox->addItem("none");//set our icon

    QPixmap px(15,15);//create pixmap,size choose yourself, by your taste
    px.fill(QColor(Qt::cyan));//all pixmap will be red
    QIcon icon(px);
    _ui->markComboBox->addItem(icon,"any");//set our icon

    px.fill(QColor(Qt::gray)); //use our pixmap again, but with another color
    icon.addPixmap(px);       //use our icon again
    _ui->markComboBox->addItem(icon,"dashed");//set our icon

    px.fill(QColor(Qt::red)); //use our pixmap again, but with another color
    icon.addPixmap(px);       //use our icon again
    _ui->markComboBox->addItem(icon,"red");//set our icon

    px.fill(QColor(Qt::blue));//use our pixmap again, but with another color
    icon.addPixmap(px);       //use our icon again
    _ui->markComboBox->addItem(icon,"blue");

    px.fill(QColor(Qt::green));//use our pixmap again, but with another color
    icon.addPixmap(px);        //use our icon again
    _ui->markComboBox->addItem(icon,"green");

    int currentMarkIndex = _ui->markComboBox->findText(_edge->mark());
    if (currentMarkIndex != -1)
        _ui->markComboBox->setCurrentIndex(currentMarkIndex);



    _labelValidator = new ListValidator(this);
    _ui->labelEdit->setValidator(_labelValidator);
}

EditEdgeDialog::~EditEdgeDialog()
{
    delete _ui;
}

void EditEdgeDialog::accept()
{
    // qDebug() << "Edge Label is: " << _ui->labelEdit->text();
    _edge->setLabel(_ui->labelEdit->text());
    _edge->setMark(_ui->markComboBox->currentText());
    _edge->setBidirectional(_ui->bidirectionalBox->isChecked());

    QDialog::accept();
}

}
