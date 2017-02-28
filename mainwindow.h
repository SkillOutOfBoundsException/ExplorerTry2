#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QtWidgets>
#include "root.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void wow();
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QFileSystemModel* model;

private slots:
    void on_treeView_clicked(const QModelIndex &index);
    void on_pushButton_3_released();
};

#endif // MAINWINDOW_H
