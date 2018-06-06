#include "ramsey.h"
#include "personaje.h"
#include "ataquer1.h"
#include "pluma.h"
#include <random>
#include "gameo.h"

extern gameO *gamme;

Ramsey::Ramsey(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/Imagenes/mini.png"));
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(plumas,SIGNAL(timeout()),this,SLOT(pluma1()));
    connect(huevos,SIGNAL(timeout()),this,SLOT(huevo()));

    timer->start(100);
    huevos->start(2000);
}

void Ramsey::win()
{
    vidaR--;
    if(vidaR==80){
        huevos->stop();
        plumas->start(1000);
        flag=1;
    }
    if(vidaR==60){
        huevos->stop();
        plumas->start(900);
        flag=1;
    }
    if(vidaR==40){
        huevos->stop();
        plumas->start(800);
        flag=1;
    }
    if(vidaR==20){
        huevos->stop();
        plumas->start(500);
        flag=1;
    }
    if(vidaR==0){
        huevos->stop();
        timer->stop();
        setPixmap(QPixmap(":/Imagenes/bye.png"));
        setPos(x(),160);
        winn = new QGraphicsTextItem();
        winn->setPlainText(QString("YOU WIN!"));
        winn->setPos(300, 100);
        winn->setDefaultTextColor(Qt::white);
        winn->setFont(QFont("Dead Kansas",50));
        gamme->scene->addItem(winn);
        musicaF->setMedia(QUrl("qrc:/sonido/Win.mp3"));
        musicaF->play();
    }
    if(numplumas>=21){
        numplumas=0;
        flag=0;
        huevos->start(2000);
        plumas->stop();
    }
}

void Ramsey::move()
{
    if(flag==0){
        if(cont==0) setPos(x(), y()+20);
        else if(cont==1) setPos(x(),y()-20);
        if(y()>220) cont=1;
        if(y()<20) cont=0;
    }
    else if(flag==1){
        setPos(x(),y()-20);
        if(y()<20){
            setPos(620,15);
            if(cont1==0) setPos(x()+40, y());
            else if(cont==1) setPos(x()-40,y());
            if(x()<621) cont=0;
            if(x()>659) cont=1;
        }
    }
    if(head==0){
        setPixmap(QPixmap(":/Imagenes/mini.png"));
        head=1;
    }
    else if(head==1){
        setPixmap(QPixmap(":/Imagenes/mini1.png"));
        head=0;
    }
}

void Ramsey::huevo()
{
    AtaqueR1 *ataq = new AtaqueR1();
    ataq->setPos(this->x(),this->y());
    scene()->addItem(ataq);
}

void Ramsey::pluma1()
{
    numplumas++;
    if(numplumas<21){
        int r=10+rand()%801;
        pluma *ataq2 = new pluma();
        ataq2->setPos(r,0);
        scene()->addItem(ataq2);
    }
    else {
        flag=0;
        huevos->start(2000);
        plumas->stop();
    }
}


