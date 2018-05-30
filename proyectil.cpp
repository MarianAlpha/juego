#include "proyectil.h"
#include <villano.h>
#include "ramsey.h"
#include  "gameo.h"

extern gameO *gamme;

proyectil::proyectil()
{
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void proyectil::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(villano)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            gamme->p1+=100;
            gamme->p2+=100;
            delete colliding_items[i];
            delete this;
            bye++;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Ramsey)){
            paloma++;
            qDebug()<<"!!!!!!!!!!!";
            scene()->removeItem(this);
            delete this;
            return;
        }
    }


    setPos(x()+20, y());
    if (x() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
