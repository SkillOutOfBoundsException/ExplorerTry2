#ifndef FILEPARENT_H
#define FILEPARENT_H
#include <QString>
#include <QtGui>
#include <QDir>
#include <QPainter>
#include <QGraphicsItem>
#include <QtCore>
#include <QDebug>

//Clase nodo, esta clase va a ser manejada por la clase Root

class FileParent{

public:
    FileParent(QFileInfo i);        //Constructor que pide el info de un archivo
    QDir* getDir();                 //getter
    FileParent* getSig();           //getter
    void setSig(FileParent* s);     //set siguiente nodo
    QFileInfo info;                 //se guarda el info
    bool selected;                  //is selected

private:
    FileParent* next;               //sguiente nodo
    void setDir(QString path);      //set directorio
    QDir* dir;                      //directorio
};

#endif // FILEPARENT_H
