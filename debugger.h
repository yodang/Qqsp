#ifndef QSPDEBUGGER_H
#define QSPDEBUGGER_H

#include<QDockWidget>
#include<QTextEdit>
#include<QLineEdit>

class Debugger: public QDockWidget{
    Q_OBJECT
public:
    Debugger(QWidget* parent=nullptr);
    Debugger(const QString& title, QWidget* parent=nullptr);

private:
    QTextEdit*  variableList;
    QTextEdit* outputText;
    QLineEdit* inputLine;

private slots:
    void command();
};

#endif // QSPDEBUGGER_H