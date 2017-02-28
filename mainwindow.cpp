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
    rip->setLabel(ui->label);
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
}

void MainWindow::on_pushButton_3_released(){
    extern Root* rip;
    if(rip->dirs.size() == 1)
        return;
    rip->dirs.pop_back();
    rip->setDir(rip->dirs.last());
    rip->refresh();
}

void MainWindow::on_pushButton_2_released(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("New text file"), tr("File name:"), QLineEdit::Normal, "filename", &ok);
    if (!ok || text.isEmpty())
        return;
    text = ui->label->text() + "/" + text + ".txt";
    QFile f(text);
    if(!f.exists()){
        qDebug() << f.fileName();
        f.open(QIODevice::ReadWrite);
        f.close();
    }
    extern Root* rip;
    rip->setDir(ui->label->text());
    rip->refresh();
}

void MainWindow::on_pushButton_released(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("New folder"), tr("Folder name:"), QLineEdit::Normal, "filename", &ok);
    if (!ok || text.isEmpty())
        return;
    QString path = ui->label->text() + "/" + text;
    QDir* newDir = new QDir(path);
    if(!newDir->exists()){
        QDir* dir = new QDir(ui->label->text());
        dir->mkdir(text);
    }
    extern Root* rip;
    rip->setDir(ui->label->text());
    rip->refresh();
}
