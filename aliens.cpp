#include "aliens.h"
#include <QDebug>
#include "gameo.h"
#include <QFont>
#include "personaje.h"
#include "proyectilalien.h"
#include <typeinfo>

aliens::aliens(QObject *parent)
{
    setPixmap((QPixmap(":/Imagenes/alien.png")));
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    connect(pum, SIGNAL(timeout()),this,SLOT(shoot()));

    timer->start(50);
    pum->start(2500);
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

void aliens::shoot()
{
    ProyectilAlien * bala = new ProyectilAlien();
    bala->setPos(this->x(),this->y());
    scene()->addItem(bala);
}
