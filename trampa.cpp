#include "trampa.h"
#include <QDebug>
#include "gameo.h"
#include <QFont>
#include "personaje.h"
#include "proyectil.h"
#include <typeinfo>


trampa::trampa(QObject *parent)
{
    setPixmap((QPixmap(":/Imagenes/trampa.png")));
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);
}

void trampa::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    if(pos().x() > 0) setPos(x()-5,y()); // mover a la izquierda
    else setPos(x(),y());
    if(pos().x()<=0){
        scene()->removeItem(this);
        delete this;
    }
}
