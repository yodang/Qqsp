#include "debugger.h"
#include<QHBoxLayout>
#include<QVBoxLayout>

Debugger::Debugger(QWidget* parent)
    :QDockWidget(parent)
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

Debugger::Debugger(const QString& title, QWidget* parent)
    :QDockWidget(title, parent)
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
    inputLine->clear();
    line.prepend("> ");
    line.append("\n");
    outputText->append(line);
}