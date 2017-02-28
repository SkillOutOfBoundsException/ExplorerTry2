#ifndef ROOT_H
#define ROOT_H
#include <QString>
#include <QtGui>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDebug>
#include <QtCore>
#include <QGraphicsScene>
#include "fileparent.h"'
#include "folders.h"

class Root{

public:
    Root(QString);
    FileParent* getHead();
    FileParent* getTail();
    QDir* getRootDir();
    QDir* getBackDir();
    void addFile(FileParent*);
    void fillList();
    void printList();
    void paintFolders();
    void refresh();

    void setDir(QString);
    void setDir(QDir*);

    void setScene(QGraphicsScene* x);

private:
    void setHead(FileParent*);
    void setTail(FileParent*);



    QGraphicsScene* scene;
    FileParent* head;
    FileParent* tail;
    int cant;
    QDir* rootDir;
    QDir* backDir;
};

#endif // ROOT_H
