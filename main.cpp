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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}
