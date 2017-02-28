#include "fileparent.h"


FileParent::FileParent(QFileInfo i){
    setSig(0);
    setDir(i.filePath());
    info = i;
    selected = false;
}

FileParent* FileParent::getSig(){
    return next;
}

QDir* FileParent::getDir(){
    return dir;
}

void FileParent::setSig(FileParent* s){
    next = s;
}

void FileParent::setDir(QString path){
    QDir* x = new QDir(path);
    dir = x;
}



