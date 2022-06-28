#ifndef QSPDEBUGGER_H
#define QSPDEBUGGER_H

#include<QFrame>
#include<QTextEdit>
#include<QLineEdit>

class Debugger: public QFrame{
    Q_OBJECT
public:
    Debugger(QWidget* parent=nullptr);

private:
    void refreshVars();

    QTextEdit*  variableList;
    QTextEdit* outputText;
    QLineEdit* inputLine;

private slots:
    void command();
};

#endif // QSPDEBUGGER_H