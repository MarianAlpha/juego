#include "villano.h"
#include <QDebug>
#include "game.h"
#include <QFont>
#include "personaje.h"
#include "proyectil.h"
#include <typeinfo>

villano::villano(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap((QPixmap(":/Imagenes/malo.png")));
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}
void villano::move()
{
    if(pos().x() > 500) setPos(x()-5,y()); // mover a la izquierda
    else setPos(x(),y());
}

