#ifndef FOLDERS_H
#define FOLDERS_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QMainWindow>
#include <QtWidgets>
#include "root.h"
#include "fileparent.h"
#include "mainwindow.h"


class Folders : public QGraphicsItem{
public:

    //constructor que pide la info del folder y la pos x  y pos y donde se dibuja
    Folders(FileParent* f, QFileInfo i, int posx, int posy);

    //estas dos funciones no se pueden dejar de escribir porque son abstractas de QGraphicsItem, la otra es el double click event
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    //atributos
    FileParent* file;
    QImage* image;
    QFileInfo info;
    int posy;
    int posx;
};

#endif // FOLDERS_H
