#include "personaje.h"
#include "gameo.h"
#include "trampa.h"
#include "aliens.h"
#include "proyectil.h"

personaje::personaje(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // draw the player
    ban_left=0;                                                         //Bandera para mover a la izquierda
    ban_right=0;                                                        //Bandera para mover a la derecha
    delta=0;                                                            //coeficiente de friccion del aire
    delta2=0.1;
    bandera=0;                                                          //Bandera para el salto

    QTimer * timer = new QTimer();                                      //Timer de movimiento
    connect(timer, SIGNAL(timeout()),this,SLOT(move_left()));           //Timer para mover a la izquierda
    connect(timer, SIGNAL(timeout()),this,SLOT(move_right()));          //Timer para mover a la derecha
    timer->start(45);                                                   //Empezar timer

}

void personaje::settBanLeft()
{
    ban_left = 1;                                                       //Define la baldera de izquierda en 1
}

void personaje::settBanRight()
{
    ban_right=1;                                                        //Define la bandera de derecha en 1
}

void personaje::resettBanLeft()
{
    ban_left=0;                                                         //Resetea la bandera izquierda
}

void personaje::resettBanRight()
{
    ban_right=0;                                                        //Resetea la bandera derecha
}

void personaje::setBandera()
{
    bandera=1;                                                          //Bandera para el salto
}

void personaje::move_right()
{
    if (ban_right == 1){                                               //Si bandera derecha esta en 1
        if (pos().x() + 100  < 980){                                   //Si la posicion en x+100 es meno a 980
            setPos(x() + 20-delta2, y());                                     //Se mueva 20 en x hacia la derecha
            //qDebug() << "right";
        }
    }
}

void personaje::move_left()
{
    if (ban_left == 1){                                               //Si la bandera izquierda esta en 1
        if (pos().x() > 0){                                           //Si la posicion en x es mayor que 0
            setPos(x() - 20+delta2, y());                                    //Se mueva 20 en x hacia la izquierda
           // qDebug() << "left";
        }
     }
}

void personaje::setHeight(int w)
{
    height = w;                                                       //Define la altura maxima para el salto
}

void personaje::jump()
{
    int posy=0;                                                      //Define la posicion y en 0
    if (bandera == 1){                                               //Si bandera salto esta en 1
        delta+=0.1;
        posy = y() -35*delta + 20*delta*delta ;                      //Posicion en y sera igual a la ecuacion de salto parabolico
        setPos(x()+10,posy);                                         //Aumentando en 10
        if (y() > height - 100){                                     //Si la posicion en y es mayor al salto -100 (altura del personaje)
            bandera = 0;                                             //Se reinicie la bandera
            delta=0;                                                 //Se reinicie el delta
            setPos(x(),height - 100);                                //Empiece a bajar
        }

    }
}

void personaje::generar()
{
    c++;                                                           //Contador para generar villanos
    if(c<11){                                                      //Si ontador es menor a 11
        enemigo = new villano();                                   //Cree un nuevo villano
        enemigo->setPos(WIDTH-100,HEIGHT-130);                     //Define la posicion al villano
        scene()->addItem(enemigo);                                 //se coloca en la escena para que sea mostrada
    }
}

void personaje::generar2()
{
    trampa * trap = new trampa();                                 //Cree un objeto trampa
    trap->setPos(WIDTH-100,320);                                  //Define la posicion de la trampa
    scene()->addItem(trap);                                       //se coloca en la escena para que sea mostrada
}

void personaje::generar3()
{
    aliens *alien = new aliens();                                 //Crea un objeto alien
    alien->setPos(WIDTH-100, 15);                                 //Define la posicion del alien(paloma)
    scene()->addItem(alien);                                      //Coloca al alien(paloma) en la escena
}
