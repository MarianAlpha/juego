#include "proyectil.h"
#include <villano.h>

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
            delete colliding_items[i];
            delete this;
            bye++;
            return;
        }
    }

    setPos(x()+20, y());
    if (x() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
