#include "aliens.h"

aliens::aliens(QObject *parent)
{
    setPixmap((QPixmap(":/Imagenes/alien.png")));
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void aliens::move()
{
    if(pos().x() > 0) setPos(x()-5,y()); // mover a la izquierda
    else setPos(x(),y());
    if(pos().x()<=0){
        scene()->removeItem(this);
        delete this;
    }
}
