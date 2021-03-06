#ifndef ROOT_H
#define ROOT_H
#include <QString>
#include <QtGui>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDebug>
#include <QtCore>
#include <QVector>
#include <QGraphicsScene>
#include "fileparent.h"'
#include "folders.h"

//Root es la lista que maneja la clase Fileparent

class Root{

public:
    Root(QString);                      //constructor que pide el path del folder que se va a abrir
    QDir* getRootDir();                 //getter
    QDir* getBackDir();                 //getter

    void fillList();                    //llena la lista
    void printList();                   //imprime la lista en el qDebug()
    void paintFolders();                //pinta los folders en la escena
    void refresh();                     //rellena la lista y pinta la escena

    void setDir(QString);               //configura el root dir
    void setDir(QDir*);                 //configura el root dir

    void setScene(QGraphicsScene* x);   //configura la escena
    void setView(QGraphicsView* x);     //configura la QGraphicsView
    void setLabel(QLabel* x);

    QVector<QDir*> dirs;                //vector que incluye todas las dirs visitadas

private:
    void addFile(FileParent*);          //agrega una file a la lista

    void setHead(FileParent*);          //configura la cabeza
    void setTail(FileParent*);          //configura la cola


    //atributos
    QGraphicsScene* scene;
    QGraphicsView* view;
    QLabel* label;
    FileParent* head;
    FileParent* tail;
    int cant;
    QDir* rootDir;
};

#endif // ROOT_H
