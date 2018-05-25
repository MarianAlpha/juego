#include "villano.h"
#include <QDebug>
#include "game.h"
#include <QFont>
#include "personaje.h"
#include "proyectil.h"
#include "proyectilejecutivo.h"
#include <typeinfo>

villano::villano(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    setPixmap((QPixmap(":/Imagenes/malo.png")));

    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    connect(pum, SIGNAL(timeout()),this,SLOT(shoot()));

    timer->start(50);
    pum->start(1000);
}
void villano::move()
{

    if(pos().x() > 500) setPos(x()-5,y()); // mover a la izquierda
    else setPos(x(),y());
}

void villano::shoot()
{
    proyectilEjecutivo * bala = new proyectilEjecutivo();
    bala->setPos(this->x(),this->y());
    scene()->addItem(bala);
}


