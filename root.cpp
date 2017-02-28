#include "root.h"

Root::Root(QString x){
    setDir(x);
    fillList();
    backDir = 0;
}

void Root::paintFolders(){
    scene->clear();
    FileParent* temp = head;
    int posx = 0;
    int posy = 0;
    while(temp != 0){
        scene->addItem(new Folders(temp, temp->info, posx, posy));
        posx = posx + 130;
        if(posx >= 530){
            posx = 0;
            posy = posy + 150;
        }
        temp = temp->getSig();
    }
    posy = (posy <= 300) ? 510 : posy + 150;
    scene->setSceneRect(0, 0, 620, posy);
}

void Root::refresh(){
    scene->clear();
    view->viewport()->update();
    fillList();
    paintFolders();
}

void Root::selectedFalse(){
    FileParent* temp = head;
    while(temp != NULL){
        temp->selected = false;
        temp = temp->getSig();
    }
}

void Root::fillList(){
    cant = 0;
    setHead(0);
    setTail(0);
    QFileInfoList y = rootDir->entryInfoList();
    y.removeFirst();
    y.removeFirst();
    foreach (QFileInfo i, y) {
        addFile(new FileParent(i));
    }
}

void Root::addFile(FileParent* a){
    if(head == 0){
        head = a;
        tail = a;
        cant = 1;
    }
    else{
        tail->setSig(a);
        tail = a;
        cant++;
    }
}

void Root::printList(){
    FileParent* temp = head;
    while(temp != 0){
        qDebug() << temp->getDir()->absolutePath();
        temp = temp->getSig();
    }
}

void Root::setHead(FileParent* x){
    head = x;
}

void Root::setTail(FileParent* x){
    tail = x;
}

void Root::setDir(QString path){
    QDir* x = new QDir(path);
    backDir = rootDir;
    rootDir = x;
}

void Root::setDir(QDir * x){
    backDir = rootDir;
    rootDir = x;
}

void Root::setScene(QGraphicsScene* x){
    scene = x;
}

void Root::setView(QGraphicsView *x){
    view = x;
}

QDir* Root::getRootDir(){
    return rootDir;
}

QDir* Root::getBackDir(){
    return backDir;
}
