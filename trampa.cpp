#include "trampa.h"
#include <QDebug>
#include "gameo.h"
#include <QFont>
#include "personaje.h"
#include "proyectil.h"
#include <typeinfo>

extern gameO *gamme;

trampa::trampa(QObject *parent)
{
    setPixmap((QPixmap(":/Imagenes/trampa.png")));
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);
}

void trampa::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->scene->removeItem(this);
            delete this;
            if(colliding_items[i]==gamme->perso){
                gamme->vid1->decrece1();
                qDebug()<<"bye1";
            } else if(colliding_items[i]==gamme->perso2){
                gamme->vid2->decrece2();
                qDebug()<<"bye2";
            }
            return;
        }
    }

    if(pos().x() > 0){
        setPos(x()-5,y());  // mover a la izquierda
        if(cont==0){
            setPixmap(QPixmap(":/Imagenes/trampa.png"));
            cont=1;
        }
        else if(cont==1){
            setPixmap(QPixmap(":/Imagenes/trampa1.png"));
            cont=2;
        }
        else if(cont==2){
            setPixmap(QPixmap(":/Imagenes/trampa2.png"));
            cont=3;
        }
        else if(cont==3){
            setPixmap(QPixmap(":/Imagenes/trampa3.png"));
            cont=4;
        }
        else if(cont==4){
            setPixmap(QPixmap(":/Imagenes/trampa4.png"));
            cont=5;
        }
        else if(cont==5){
            setPixmap(QPixmap(":/Imagenes/trampa5.png"));
            cont=6;
        }
        else if(cont==6){
            setPixmap(QPixmap(":/Imagenes/trampa6.png"));
            cont=0;
        }
    }
    else setPos(x(),y());
    if(pos().x()<=0){
        scene()->removeItem(this);
        delete this;
    }
}
