#include "aliens.h"
#include <QDebug>
#include "gameo.h"
#include <QFont>
#include "personaje.h"
#include "proyectilalien.h"
#include <typeinfo>

aliens::aliens(QObject *parent)
{
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));  //Timer para mover la paloma
    connect(pum, SIGNAL(timeout()),this,SLOT(shoot()));   //Timer para disparar los huevos

    timer->start(50);                                     //Inicia el timer de movimiento
    pum->start(2500);                                     //Inicia el timer de disparo
}

void aliens::move()
{
    if(pos().x() > 0){                                          //Si la posicion de la  paloma es mayor a 0
        setPos(x()-5,y());                                      //Restele 5 la posicion en x
        if(cont==0){                                            //Si cont es igual a 0
            setPixmap((QPixmap(":/Imagenes/paloma1.png")));     //La primera imagen del sprite
            cont=1;                                             //Cont=1
        }else if(cont==1){                                      //Si cont es igual a 1
            setPixmap((QPixmap(":/Imagenes/paloma2.png")));     //La segunda imagen del sprite
            cont=2;                                             //Cont=2
        } else if(cont==2){                                     //Si cont es igual 2
            setPixmap((QPixmap(":/Imagenes/paloma3.png")));     //La tercera imagen del sprite
            cont=3;                                             //Cont=3
        } else if(cont==3){                                     //Si cont es igual a 3
            setPixmap((QPixmap(":/Imagenes/paloma4.png")));     //La cuarta imagen del sprite
            cont=4;                                             //Cont=4
        } else if(cont==4){                                     //Si cont es igual a 4
            setPixmap((QPixmap(":/Imagenes/paloma5.png")));     //La quinta imagen del aprite
            cont=5;                                             //Cont=5
        } else if(cont==5){                                     //Si cont es igual a 5
            setPixmap((QPixmap(":/Imagenes/paloma6.png")));     // La sexta imagen del sprite
            cont=6;                                             //Cont=6
        } else if(cont==6){                                     //Si cont es igual a 6
            setPixmap((QPixmap(":/Imagenes/paloma7.png")));     //La septima imagen del sprite
            cont=7;                                             //cont=7
        } else if(cont==7){                                     //Si cont es igual a 7
            setPixmap((QPixmap(":/Imagenes/paloma8.png")));     //La octava imagen de sprite
            cont=8;                                             //cont=8
        } else if(cont==8){                                     //Si cont es igual a 8
            setPixmap((QPixmap(":/Imagenes/paloma9.png")));     //La novena imagen del sprite
            cont=0;                                             //Reinicia el cont
        }
    } else setPos(x(),y());                                     //De lo contrario se quede quieto
    if(pos().x()<=0){                                           //Si la posicion queda siendo igual o menor a cero
        scene()->removeItem(this);                              //Elimina la paloma de la escena
        delete this;                                            //Elimina el puntero
    }
}

void aliens::shoot()
{
    ProyectilAlien * bala = new ProyectilAlien();               //Crea un objeto tipo proyectil Alien
    bala->setPos(this->x(),this->y());                          //La bala se genera segun la posicion de la paloma
    scene()->addItem(bala);                                     //Añade el proyectil a la escena
}
