#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfoList>
#include <QProcess>
#include <QFileInfo>
#include <QUrl>
#include <QtCore>
#include <QtWidgets>
#include "fileparent.h"
#include "root.h"

Root* rip = new Root(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
Ui::MainWindow* mui;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    mui = w.ui;



    w.show();

    return a.exec();
}
