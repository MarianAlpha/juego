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
            setPixmap((QPixmap(":/Imagenes/paloma2.png")));     //La segunda imagen del spray
            cont=2;
        } else if(cont==2){
            setPixmap((QPixmap(":/Imagenes/paloma3.png")));
            cont=3;
        } else if(cont==3){
            setPixmap((QPixmap(":/Imagenes/paloma4.png")));
            cont=4;
        } else if(cont==4){
            setPixmap((QPixmap(":/Imagenes/paloma5.png")));
            cont=5;
        } else if(cont==5){
            setPixmap((QPixmap(":/Imagenes/paloma6.png")));
            cont=6;
        } else if(cont==6){
            setPixmap((QPixmap(":/Imagenes/paloma7.png")));
            cont=7;
        } else if(cont==7){
            setPixmap((QPixmap(":/Imagenes/paloma8.png")));
            cont=8;
        } else if(cont==8){
            setPixmap((QPixmap(":/Imagenes/paloma9.png")));
            cont=0;
        }
    } else setPos(x(),y());
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
