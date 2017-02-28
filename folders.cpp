#include "folders.h"
#include <QFontDatabase>

//CAMBIAR LA VARIABLE PA CON EL ROOT DEL PROYECTO ANTES DE CORRER

Folders::Folders(FileParent* f, QFileInfo i, int x, int y){
    file = f;
    info = i;
    QString pa = "C:\\Users\\Diegu7-CB1\\Documents\\C++\\ExplorerTry2\\";
    QString th = "archivo2.png";
    if(info.fileName().contains(".txt"))
        th = "txt2.png";
    else if(info.fileName().contains(".png", Qt::CaseInsensitive) || info.fileName().contains(".jpeg") || info.fileName().contains(".jpg", Qt::CaseInsensitive)   || info.fileName().contains(".gif")  || info.fileName().contains(".bmp"))
        th = "image.png";
    else if(info.fileName().contains(".xlsm") || info.fileName().contains(".xslx") || info.fileName().contains(".xsl"))
        th = "excel.png";
    else if(info.fileName().contains(".docx"))
        th = "word.png";
    else if(info.fileName().contains(".pptx"))
        th = "ppt.png";
    else if(info.fileName().contains(".dll"))
        th = "dll.png";
    else if(info.fileName().contains(".mp3") || info.fileName().contains(".wav") || info.fileName().contains(".acc") || info.fileName().contains(".flac") || info.fileName().contains(".ogg"))
        th = "music.png";
    else if(info.fileName().contains(".exe") || info.fileName().contains(".msi") || info.fileName().contains(".lnk") || info.fileName().contains(".appref-ms"))
        th = "exe.png";
    else if(info.isDir())
        th = "folder.png";
    QString path = pa + th;
    image = new QImage(path);
    posx = x;
    posy = y;
}

QRectF Folders::boundingRect() const{
    return QRectF(posx-10,posy,120,150);
}

void Folders::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rec = boundingRect();
    QFont* font = new QFont("Times [Adobe]", 10, -1, false);
    painter->setFont(*font);
    if(file->selected){
        QColor color(229,241,251);
        painter->fillRect(QRectF(posx-10,posy,120,145), color);
    }
    painter->drawImage(QRectF(posx,posy,100,150), *image, QRectF(0,0,100,150));
    painter->drawText(QRectF(posx,posy + 100,100, 50), /*Qt::AlignBottom | */Qt::AlignCenter | Qt::TextWordWrap | Qt::TextDontClip, info.fileName());
}

void Folders::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    extern Root* rip;
    if(!info.isDir())
        QDesktopServices::openUrl(QUrl("file:///" + info.absoluteFilePath()));
    else{
        rip->setDir(info.absoluteFilePath());
        rip->refresh();
    }
}

void Folders::mousePressEvent(QGraphicsSceneMouseEvent *event){
    extern Root* rip;
    rip->selectedFalse();
    file->selected = true;
    update();
}


