#include "debugger.h"
#include "qsp/variables.h"
#include "comtools.h"

#include<QHBoxLayout>
#include<QVBoxLayout>

Debugger::Debugger(QWidget* parent)
    :QFrame(parent)
{
    variableList=new QTextEdit();
    variableList->setReadOnly(true);
    outputText=new QTextEdit();
    outputText->setReadOnly(true);
    inputLine=new QLineEdit();

    auto vlayout=new QVBoxLayout();
    vlayout->addWidget(outputText);
    vlayout->addWidget(inputLine);
    
    auto hlayout=new QHBoxLayout();
    hlayout->addWidget(variableList);
    hlayout->addLayout(vlayout);
    setLayout(hlayout);
    
    connect(inputLine, &QLineEdit::returnPressed, this, &Debugger::command);
}

void Debugger::command()
{
    auto line=inputLine->text();
    auto cmd=line;
    inputLine->clear();
    line.prepend("> ");
    line.append("\n");
    outputText->append(line);

    if(cmd=="clear")
        outputText->clear();
    else if(cmd=="refresh")
        refreshVars();
    else if(cmd.startsWith("print"))
    {
        auto varName=cmd.split(" ")[1];
        printVar(varName);
    }
}

void Debugger::refreshVars()
{
    variableList->clear();
    for(int i=0; i<QSP_VARSCOUNT; i++)
    {
        if(qspVars[i].Name!=0)
        {
            variableList->append(QSPTools::qspStrToQt(qspVars[i].Name));
        }
    }

}

void Debugger::printVar(const QString& name)
{
    int results;
    QSP_CHAR* values;
    QSPGetVarValues(reinterpret_cast<const QSP_CHAR*>(name.utf16()), 0, &results, &values);
    outputText->append(QSPTools::qspStrToQt(values));
}