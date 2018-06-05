#include "pluma.h"
#include "personaje.h"
#include "gameo.h"

extern gameO *gamme;

pluma::pluma(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/Imagenes/pluma.png"));
    connect(plum,SIGNAL(timeout()),this,SLOT(move()));
    plum->start(20);
}

void pluma::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->scene->removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(),y()+20);
    if(y()>300) {
        gamme->scene->removeItem(this);
        delete this;
    }
}
