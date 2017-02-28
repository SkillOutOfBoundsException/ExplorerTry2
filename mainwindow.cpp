#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->label->setStyleSheet("background-color: rgb(225,225,225);border:1px solid rgb(185,193,205);");

    QString path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    model = new QFileSystemModel(this);
    model->setRootPath(path);
    model->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    ui->treeView->setModel(model);
    ui->label->setText(path);

    QModelIndex index = model->index(path);

    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->resizeColumnToContents(index.column());

    extern Root* rip;

    rip->setScene(scene);
    rip->setView(ui->graphicsView);
    rip->paintFolders();


    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index){    
    QString path = model->fileInfo(index).absoluteFilePath();
    extern Root* rip;
    rip->setDir(path);
    rip->refresh();
    ui->label->setText(path);
}

void MainWindow::on_pushButton_3_released(){
    extern Root* rip;
    if(rip->getBackDir() == NULL)
        return;
    rip->setDir(rip->getBackDir());
    rip->refresh();
    ui->label->setText(rip->getBackDir()->absolutePath());
}
