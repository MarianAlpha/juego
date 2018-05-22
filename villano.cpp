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
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}
void villano::move()
{
    setPos(x()-5,y()); // mover a la izquierda
    if (x() < 400){
        scene()->removeItem(this);
        delete this;
    }
}

