#include "ataquer1.h"
#include "personaje.h"
#include "gameo.h"

extern gameO *gamme;

AtaqueR1::AtaqueR1(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/Imagenes/HR1.png"));
    connect(vel,SIGNAL(timeout()),this,SLOT(move()));
    vel->start(60);
}

void AtaqueR1::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->scene->removeItem(this);
            delete this;
            return;
        }
    }

    if(y()<=290) setPos(x(), y()+20);
    if(y()>291){
        setPos(x()-20, y());
        if(mover==0){
            setPixmap(QPixmap(":/Imagenes/HR2.png"));
            mover=1;
        }
        else if(mover==1){
            setPixmap(QPixmap(":/Imagenes/HR3.png"));
            mover=2;
        }
        else if(mover==2){
            setPixmap(QPixmap(":/Imagenes/HR4.png"));
            mover=3;
        }
        else if(mover==3){
            setPixmap(QPixmap(":/Imagenes/HR5.png"));
            mover=4;
        }
        else if(mover==4){
            setPixmap(QPixmap(":/Imagenes/HR6.png"));
            mover=5;
        }
        else if(mover==5){
            setPixmap(QPixmap(":/Imagenes/HR7.png"));
            mover=6;
        }
        else if(mover==6){
            setPixmap(QPixmap(":/Imagenes/HR8.png"));
            mover=0;
        }
    }
    if(x()<0){
        gamme->scene->removeItem(this);
        delete this;
    }
}
