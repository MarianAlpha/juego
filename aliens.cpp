#include "aliens.h"
#include <QDebug>
#include "gameo.h"
#include <QFont>
#include "personaje.h"
#include "proyectilalien.h"
#include <typeinfo>

aliens::aliens(QObject *parent)
{
    //setPixmap((QPixmap(":/Imagenes/paloma1.png")));
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    connect(pum, SIGNAL(timeout()),this,SLOT(shoot()));

    timer->start(50);
    pum->start(2500);
}

void aliens::move()
{
    if(pos().x() > 0){
        setPos(x()-5,y());
        if(cont==0){
            setPixmap((QPixmap(":/Imagenes/paloma1.png")));
            cont=1;
        }else if(cont==1){
            setPixmap((QPixmap(":/Imagenes/paloma2.png")));
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
