/*!
 * \file
 */
#include "ruleedit.hpp"
#include "ui_ruleedit.h"

#include "rule.hpp"
#include "helpdialog.hpp"
#include "graph.hpp"

#include <QDebug>

namespace Developer {

RuleEdit::RuleEdit(QWidget *parent)
    : QWidget(parent)
    , _ui(new Ui::RuleEdit)
    , _rule(0)
{
    _ui->setupUi(this);
}

RuleEdit::~RuleEdit()
{
    delete _ui;
}

void RuleEdit::setRule(Rule *rule)
{
    _rule = rule;

    _ui->nameEdit->setText(_rule->name());
    _ui->documentationEdit->setPlainText(_rule->documentation());
    _ui->rhsGraph->setLinkedGraph(0);
    _ui->lhsGraph->setGraph(_rule->lhs());
    connect(_rule->lhs(), SIGNAL(graphChanged()),
            this, SLOT(lhsChanged()));
    _ui->rhsGraph->setGraph(_rule->rhs());
    connect(_rule->rhs(), SIGNAL(graphChanged()),
            this, SLOT(rhsChanged()));
    _ui->rhsGraph->setLinkedGraph(_rule->lhs());
    _ui->conditionsEdit->setPlainText(_rule->condition());

    qDebug() << "** Updating variables";
    updateVariables();
}

void RuleEdit::showInjectiveHelp()
{
    HelpDialog *dialog = new HelpDialog(HelpDialog::Injective, this);
    dialog->exec();
}

void RuleEdit::nameChanged(QString name)
{
    _rule->setName(name);
}

void RuleEdit::documentationChanged()
{
    _rule->setDocumentation(_ui->documentationEdit->toPlainText());
}

void RuleEdit::lhsChanged()
{
    updateVariables();
    updateInterface();
}

void RuleEdit::rhsChanged()
{
    updateVariables();
    updateInterface();
}

void RuleEdit::injectiveChanged(int index)
{
    switch(index)
    {
    case 1:
        break;
    default:
        break;
    }
}

void RuleEdit::conditionChanged()
{
    if(_rule == 0)
        return;

    _ui->conditionsEdit->parse();

    _rule->setCondition(_ui->conditionsEdit->toPlainText().trimmed());
}

void RuleEdit::updateVariables()
{
    _ui->variablesWidget->clear();

    QStringList headers;
    headers << "Identifier" << "Type";
    _ui->variablesWidget->setHorizontalHeaderLabels(headers);

    QStringList lhsVariables = _rule->lhs()->variables();
    QStringList rhsVariables = _rule->rhs()->variables();


    QStringList types;
    types << "List" << "Atom" << "String" << "Integer" << "Character";


    // Obtain all the variables appearing in the LHS and RHS graphs
    QStringList graphVariables = lhsVariables;
    graphVariables += rhsVariables;

    graphVariables.removeDuplicates();

    qDebug() << "RuleEdit::updateVariables(): the variables in LHS+RHS are " << graphVariables.join(" ");

    // Obtain all variables that are currently declared in the rule specification
    QStringList variables;
    std::vector<param_t> varDeclarations = _rule->variables();
    for (std::vector<param_t>::const_iterator it = varDeclarations.begin(); it != varDeclarations.end(); ++it)
    {
        QString varType = QString::fromStdString(it->type);  
        std::vector<std::string> varList = it->variables;  
        qDebug() << "RuleEdit::updateVariables(): the rule has " << varList.size() << " variables of type " << varType;
        for (std::vector<std::string>::const_iterator itt = varList.begin(); itt != varList.end(); ++itt)
        {
            QString variable = QString::fromStdString(*itt);

            if (!graphVariables.contains(variable)) continue;

            variables << variable;

            // Add to the Variables Widget with respective type properly selected
            QTableWidgetItem *item = new QTableWidgetItem(variable);
            item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

            _ui->variablesWidget->setItem(variables.length()-1, 0, item);
    
            QComboBox *comboBox = new QComboBox(_ui->variablesWidget);
            comboBox->addItems(types);

            // check which type to be selected            
            if (varType == "int") comboBox->setCurrentIndex(3);
            else if (varType == "char") comboBox->setCurrentIndex(4);
            else if (varType == "string") comboBox->setCurrentIndex(2);
            else if (varType == "atom") comboBox->setCurrentIndex(1);
            else if (varType == "list") comboBox->setCurrentIndex(0);

            connect(comboBox, SIGNAL(activated(int)), this, SLOT(saveVariables()));
            _ui->variablesWidget->setCellWidget(variables.length()-1, 1, comboBox);
        }
        
    }
    qDebug() << "RuleEdit::updateVariables(): the declared variables are " << variables.join(" ");

    
    // Remove all the LHS variables from the RHS set, those that
    // remain are currently errors as they do not exist in the LHS
    // These errors will be marked as red in the Widget
    QStringList diff = rhsVariables;
    for(int i = 0; i < lhsVariables.length(); ++i)
    {
        QString variable = lhsVariables.at(i);
        if(diff.contains(variable))
            diff.removeOne(variable);
    }
    qDebug() << "RuleEdit::updateVariables(): the bad variables in RHS are " << diff.join(" ");

    // Check which graph variables are already declared in the rule specification
    // If already declared, no need to add it again to the Variables Widget   
    for(int i = 0; i < graphVariables.length(); ++i)
    {
        QString variable = graphVariables.at(i);
        if(variables.contains(variable))
             {graphVariables.removeOne(variable); --i;}
    }

    qDebug() << "RuleEdit::updateVariables(): the undeclared variables in LHS+RHS are " << graphVariables.join(" ");

    _ui->variablesWidget->setRowCount(graphVariables.length() + variables.length());


    for(int i = 0; i < graphVariables.length(); ++i)
    {
        QString variable = graphVariables.at(i);
        QTableWidgetItem *item = new QTableWidgetItem(variable);
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        if(diff.contains(variable))
        {
            item->setToolTip(tr("The variable '%1' does not appear in the LHS. "
                                "All variables in the RHS must appear in the "
                                "LHS graph.").arg(variable));
            item->setBackgroundColor(QColor(0xff,0xaa,0xaa,0x55));
        }

        _ui->variablesWidget->setItem(i + variables.length(), 0, item);

        QComboBox *comboBox = new QComboBox(_ui->variablesWidget);
        comboBox->addItems(types);

        connect(comboBox, SIGNAL(activated(int)), this, SLOT(saveVariables()));
        _ui->variablesWidget->setCellWidget(i + variables.length(), 1, comboBox);
    }

    // Snapshot the displayed variables and save to Rule
    saveVariables();
}

// Takes a snapshot of the current variables in the Variables Widget
// Saves the snapshot to the underlying Rule
void RuleEdit::saveVariables()
{
    QTableWidget* table = _ui->variablesWidget;
    QStringList listVars;
    QStringList atomVars;
    QStringList intVars;
    QStringList charVars;
    QStringList stringVars;

    // Iterate over the variables in the table
    for (int i = 0; i < table->rowCount(); ++i)
    {
        QTableWidgetItem *widget = table->item(i, 0);
        QString var = widget->text();

        QString type = ((QComboBox*) table->cellWidget(i, 1))->currentText();

        if (type == "List") listVars << var;
        else if (type == "Atom") atomVars << var;
        else if (type == "String") stringVars << var;
        else if (type == "Integer") intVars << var;
        else if (type == "Character") charVars << var;

    }
  
    //qDebug() << "Found this many variables: " << QVariant(listVars.length() + atomVars.length() + stringVars.length() + intVars.length() + charVars.length()).toString();    

    // Construct a resulting vector of variables lists
    std::vector<param_t> result;
    
    if (!listVars.isEmpty())
    {
        param_t vars;
        vars.type = "list";
        QStringListIterator javaStyleIterator(listVars);
        while (javaStyleIterator.hasNext())
            vars.variables.push_back(javaStyleIterator.next().toStdString());
        result.push_back(vars);
    }
    
    if (!atomVars.isEmpty())
    {
        param_t vars;
        vars.type = "atom";
        QStringListIterator javaStyleIterator(atomVars);
        while (javaStyleIterator.hasNext())
            vars.variables.push_back(javaStyleIterator.next().toStdString());
        result.push_back(vars);
    }
    
    if (!intVars.isEmpty())
    {
        param_t vars;
        vars.type = "int";
        QStringListIterator javaStyleIterator(intVars);
        while (javaStyleIterator.hasNext())
            vars.variables.push_back(javaStyleIterator.next().toStdString());
        result.push_back(vars);
    }
    
    if (!charVars.isEmpty())
    {
        param_t vars;
        vars.type = "char";
        QStringListIterator javaStyleIterator(charVars);
        while (javaStyleIterator.hasNext())
            vars.variables.push_back(javaStyleIterator.next().toStdString());
        result.push_back(vars);
    }
    
    if (!stringVars.isEmpty())
    {
        param_t vars;
        vars.type = "string";
        QStringListIterator javaStyleIterator(stringVars);
        while (javaStyleIterator.hasNext())
            vars.variables.push_back(javaStyleIterator.next().toStdString());
        result.push_back(vars);
    }

    QString saveText;
    // Debug the vector of results
		/*for (std::vector<param_t>::iterator it = result.begin(); it != result.end(); ++it)
		{
				param_t vvar = *it; 	// This is a list of variables of the same type
				//qDebug() << "     " << vvar.type.c_str() <<": " ;
				for (std::vector<std::string>::iterator itt = vvar.variables.begin(); 
						 itt != vvar.variables.end();
						 ++itt )
				{
					std::string var = *itt;
				  //qDebug() << "          " << var.c_str();
					saveText += var.c_str();
					if (itt != vvar.variables.end() - 1) 
						saveText += ", ";
					else
						{ 
							saveText += " : "; 
							saveText+= vvar.type.c_str() ; 
							
							if (it != (result.end() - 1))			
								saveText += ";";			
				
							saveText += "\n"; 
						} 
				}
		}
    qDebug() << "=======" ;
    qDebug() << saveText ;
    qDebug() << "=======" ;*/
    
    // Save the vector
    _rule->setVariables(result);
}

void RuleEdit::updateInterface()
{
    std::vector<Node *> lhsNodes = _rule->lhs()->nodes();
    std::vector<Node *> rhsNodes = _rule->rhs()->nodes();

    std::vector<std::string> elements;

    QStringList debug;

    // The interface is the set of nodes with same ids

    for (std::vector<Node *>::const_iterator it = lhsNodes.begin(); it != lhsNodes.end(); it++)
    {
        Node* lhsNode = *it;
        QString id = lhsNode->id();
        for (std::vector<Node *>::const_iterator itt = rhsNodes.begin(); itt != rhsNodes.end(); itt++)
        {
            Node* rhsNode = *itt;
            if (rhsNode->isPhantomNode()) continue;
            if (rhsNode->id() == id)
                { elements.push_back(id.toStdString()); debug << id; }         
        }    
    }

    qDebug() << "The common nodes are: " << debug.join(" ");

    interface_t result;
    result.elements = elements;

    _rule->setInterface(result);

}




}
