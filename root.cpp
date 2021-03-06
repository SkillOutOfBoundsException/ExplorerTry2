#include "root.h"

Root::Root(QString x){
    setDir(x);
    fillList();
}

void Root::paintFolders(){
    scene->clear();
    FileParent* temp = head;
    int posx = -130;
    int posy = 0;
    while(temp != 0){
        posx = posx + 130;
        if(posx >= 530){
            posx = 0;
            posy = posy + 150;
        }
        scene->addItem(new Folders(temp->info, posx, posy));
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
    label->setText(rootDir->absolutePath());
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
    if(dirs.isEmpty() || dirs.last() != x)
        dirs.push_back(x);
    rootDir = x;
}

void Root::setDir(QDir * x){
    if(dirs.last() != x)
        dirs.push_back(x);
    rootDir = x;
}

void Root::setScene(QGraphicsScene* x){
    scene = x;
}

void Root::setView(QGraphicsView *x){
    view = x;
}

void Root::setLabel(QLabel *x){
    label = x;
}

QDir* Root::getRootDir(){
    return rootDir;
}
