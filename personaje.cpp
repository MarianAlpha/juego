#include "personaje.h"
#include "game.h"
#include "proyectil.h"

personaje::personaje(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // draw the player
    setPixmap(QPixmap(":/Imagenes/p1.png"));
    p2=setPixmap();
    bandera = 0;
    bandera=0;
    delta = 0;
}

void personaje::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        if (pos().x() > 0){
            setPos(x()-10,y());
            if(cont<2){
                setPixmap(QPixmap(":/Imagenes/p11.png"));
                cont++;
            }
            else{
                setPixmap(QPixmap(":/Imagenes/p22"));
                cont=0;
            }
        }
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100  < 1000){
            setPos(x()+10,y());
            if(cont<2){
                setPixmap(QPixmap(":/Imagenes/p1.png"));
                cont++;
            }
            else{
                setPixmap(QPixmap(":/Imagenes/p2"));
                cont=0;
            }
        }
    }
    else if (event->key() == Qt::Key_Up){
        bandera=1;
    }
    if (event->key() == Qt::Key_Space){
        proyectil *proy= new proyectil();
        setPixmap(QPixmap(":/Imagenes/disparo.png"));
        proy->setPos(x(),y());
        scene()->addItem(proy);
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
        setPos(x(),posy);
        if (y() > height - 100){
            bandera = 0;
            delta=0;
            setPos(x(),height - 100);
        }

    }
}
