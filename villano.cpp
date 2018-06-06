#include "villano.h"
#include <QDebug>
#include "gameo.h"
#include <QFont>
#include "personaje.h"
#include "proyectil.h"
#include "proyectilejecutivo.h"
#include <typeinfo>

villano::villano(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    setPixmap((QPixmap(":/Imagenes/mallo1.png")));

    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    connect(pum, SIGNAL(timeout()),this,SLOT(shoot()));

    timer->start(50);
    pum->start(2000);
}
void villano::move()
{

    if(pos().x() > 500){
        setPos(x()-5,y());
        if(cont==0){
            setPixmap((QPixmap(":/Imagenes/mallo1.png")));
            cont=1;
        }else if(cont==1){
            setPixmap((QPixmap(":/Imagenes/mallo2.png")));
            cont=2;
        } else if(cont==2){
            setPixmap((QPixmap(":/Imagenes/mallo3.png")));
            cont=3;
        } else if(cont==3){
            setPixmap((QPixmap(":/Imagenes/mallo4.png")));
            cont=4;
        } else if(cont==4){
            setPixmap((QPixmap(":/Imagenes/mallo5.png")));
            cont=5;
        } else if(cont==5){
            setPixmap((QPixmap(":/Imagenes/mallo6.png")));
            cont=0;
        }
    }
    else setPos(x(),y());
}

void villano::shoot()
{
    proyectilEjecutivo * bala = new proyectilEjecutivo();
    disp->setMedia(QUrl("qrc:/sonido/disparomalo.mp3"));
    disp->play();
    bala->setPos(this->x()-20,this->y()+25);
    scene()->addItem(bala);
}


