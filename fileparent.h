#ifndef FILEPARENT_H
#define FILEPARENT_H
#include <QString>
#include <QtGui>
#include <QDir>
#include <QPainter>
#include <QGraphicsItem>
#include <QtCore>
#include <QDebug>

class FileParent{

public:
    FileParent(QFileInfo i);
    QDir* getDir();
    FileParent* getSig();
    void setSig(FileParent* s);
    QFileInfo info;

protected:
    FileParent* next;
    void setDir(QString path);
    QDir* dir;

};

#endif // FILEPARENT_H
