#include "ramsey.h"
#include "personaje.h"
#include "ataquer1.h"
#include "gameo.h"

Ramsey::Ramsey(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/Imagenes/mini.png"));
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(huevos,SIGNAL(timeout()),this,SLOT(huevo()));

    timer->start(100);
    huevos->start(2000);
}

void Ramsey::move()
{
    if(cont==0) setPos(x(), y()+20);
    else if(cont==1) setPos(x(),y()-20);
    if(y()>220) cont=1;
    if(y()<20) cont=0;
    if(head==0){
        setPixmap(QPixmap(":/Imagenes/mini.png"));
        head=1;
    }
    else if(head==1){
        setPixmap(QPixmap(":/Imagenes/mini1.png"));
    }
}

void Ramsey::huevo()
{
    AtaqueR1 *ataq = new AtaqueR1();
    ataq->setPos(this->x(),this->y());
    scene()->addItem(ataq);
}

