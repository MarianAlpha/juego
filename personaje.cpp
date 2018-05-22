#include "personaje.h"
#include "game.h"
#include "proyectil.h"

personaje::personaje(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // draw the player
    ban_left=0;
    ban_right=0;
    delta=0;
    bandera=0;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move_left()));
    connect(timer, SIGNAL(timeout()),this,SLOT(move_right()));
    timer->start(45);
}

void personaje::settBanLeft()
{
    ban_left = 1;
}

void personaje::settBanRight()
{
    ban_right=1;
}

void personaje::resettBanLeft()
{
    ban_left=0;
}

void personaje::resettBanRight()
{
    ban_right=0;
}

void personaje::setBandera()
{
    bandera=1;
}

void personaje::move_right()
{
    if (ban_right == 1){
        if (pos().x() + 100  < 800){
            setPos(x() + 20, y());
            //qDebug() << "right";
        }
    }
}

void personaje::move_left()
{
    if (ban_left == 1){
        if (pos().x() > 0){
            setPos(x() - 20, y());
           // qDebug() << "left";
        }
     }
}

void personaje::setHeight(int w)
{
    height = w;
}

void personaje::jump()
{
    int posy=0;
    if (bandera == 1){
        delta+=0.1;
        posy = y() -35*delta + 20*delta*delta ;
        setPos(x()+10,posy);
        if (y() > height - 100){
            bandera = 0;
            delta=0;
            setPos(x(),height - 100);
        }

    }
}

void personaje::generar()
{
    c++;
    if(c<4){
        villano * enemigo = new villano();
        enemigo->setPos(WIDTH-100,HEIGHT-130);
        scene()->addItem(enemigo); //se coloca en la escena para que sea mostrada
    }
}
