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
            gamme->p1=gamme->p1+100;
            gamme->p2=gamme->p2+100;
            delete colliding_items[i];
            bye++;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Ramsey)){
            paloma++;
            gamme->p1=gamme->p1+200;
            gamme->p2=gamme->p2+200;
            gamme->ramsey->win();
            qDebug()<<"!!!!!!!!!!!"<<gamme->ramsey->vidaR;
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
    if(gamme->vid1->vj1<=0){
        timer->stop();
    }
}
