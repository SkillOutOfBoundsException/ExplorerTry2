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
#include "mainwindow.h"


class Folders : public QGraphicsItem{
public:
    Folders(QFileInfo i, int posx, int posy);

    //estas dos funciones no se pueden dejar de escribir porque son abstractas de QGraphicsItem
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

    QImage* image;
    QFileInfo info;
    int posy;
    int posx;
    bool selected;
};

#endif // FOLDERS_H
