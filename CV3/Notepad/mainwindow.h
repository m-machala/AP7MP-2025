#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    QTextEdit * mainText = NULL;

protected slots:
    void saveTextAs();
    void openText();

};
#endif // MAINWINDOW_H
