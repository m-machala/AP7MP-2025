#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QIODevice>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(100, 100, 640, 480);

    QMenu *fileMenu = new QMenu("File");
    menuBar()->addMenu(fileMenu);

    QAction *actionOpen = new QAction("Open text file...");
    actionOpen->setShortcut(QKeySequence::Open);
    fileMenu->addAction(actionOpen);
    connect(actionOpen, &QAction::triggered, this, &MainWindow::openText);

    QAction *actionSaveAs = new QAction("Save text as...");
    actionSaveAs->setShortcut(QKeySequence::SaveAs);
    fileMenu->addAction(actionSaveAs);
    connect(actionSaveAs, &QAction::triggered, this, &MainWindow::saveTextAs);

    fileMenu->addSeparator();

    QAction *actionQuit = new QAction("Quit");
    actionQuit->setShortcut(QKeySequence::Close);
    fileMenu->addAction(actionQuit);
    connect(actionQuit, &QAction::triggered, this, &MainWindow::close);

    mainText = new QTextEdit(this);
    setCentralWidget(mainText);
}

MainWindow::~MainWindow() {}

void MainWindow::openText() {
    qDebug() << "Opening text...";

    QString fileName = QFileDialog::getOpenFileName(this, "Open text file...", "", "Text files (*.txt)");

    if(!fileName.isEmpty()) {
        QFile file(fileName);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            mainText->setText(in.readAll());
            file.close();
        }
        else {
            QMessageBox::critical(this, "Simple Notepad", "Unable to open text.");
        }
    }
    else {
        QMessageBox::critical(this, "Simple Notepad", "File name empty.");
    }
}

void MainWindow::saveTextAs() {
    qDebug() << "Saving text...";

    QString fileName = QFileDialog::getSaveFileName(this, "Save text as", "", "Text files (*.txt)");

    if(!fileName.isEmpty()) {
        QFile file(fileName);

        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << mainText->toPlainText();
            file.close();
        }
        else {
            QMessageBox::critical(this, "Simple Notepad", "Unable to open text.");
        }

    }
    else {
        QMessageBox::critical(this, "Simple Notepad", "File name empty.");
    }
}
