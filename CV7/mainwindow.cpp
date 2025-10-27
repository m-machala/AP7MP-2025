#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QClipboard>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QFileSystemModel();
    model->setRootPath(QDir::currentPath());

    ui->treeView->setModel(model);
    ui->listView->setModel(model);

    ui->listView->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction *actionClipboard = new QAction("Copy to clipboard");
    ui->listView->addAction(actionClipboard);

    QAction *actionDetail = new QAction("Show detail");
    ui->listView->addAction(actionDetail);

    connect(ui->treeView, &QTreeView::clicked, ui->listView, &QListView::setRootIndex);
    connect(ui->treeView, &QTreeView::clicked, [&](const QModelIndex &index){
        ui->history->append(model->filePath(index));
    });
    connect(actionClipboard, &QAction::triggered, this, &MainWindow::copyToClipboard);
    connect(actionDetail, &QAction::triggered, this, &MainWindow::showDetail);
}

void MainWindow::showDetail() {
    QFileInfo fileInfo = model->fileInfo(ui->listView->currentIndex());
    QMessageBox::information(this, "File Browser", QString("File name: %1\nFile size: %2\nIs directory %3")
                                                       .arg(fileInfo.fileName())
                                                       .arg(fileInfo.size())
                                                       .arg(fileInfo.isDir()?"Yes":"No"));
}

void MainWindow::copyToClipboard() {
    QString filePath = model->filePath(ui->listView->currentIndex());
    qApp->clipboard()->setText(filePath);
}

MainWindow::~MainWindow()
{
    delete ui;
}
