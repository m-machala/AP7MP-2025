#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_withoutDPH_textChanged(const QString &arg1)
{
    MainWindow::updateValue(arg1);
}

void MainWindow::updateValue(QString inputString) {
    float inputValue = (float)inputString.toInt();
    if(ui->twelvePercent->isChecked()) {
        ui->withDPH->setText(QVariant(inputValue + inputValue * 0.12).toString());
    }
    else {
        ui->withDPH->setText(QVariant(inputValue + inputValue * 0.21).toString());
    }
}


void MainWindow::on_twelvePercent_clicked()
{
    QString currentValue = ui->withoutDPH->text();
    MainWindow::updateValue(currentValue);
}


void MainWindow::on_twentyOnePercent_clicked()
{
    MainWindow::on_twelvePercent_clicked();
}

