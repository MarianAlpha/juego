#include "ataquer1.h"
#include "personaje.h"
#include "gameo.h"

extern gameO *gamme;

AtaqueR1::AtaqueR1(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/Imagenes/HR1.png"));                          //Define la imagen del huevo
    connect(vel,SIGNAL(timeout()),this,SLOT(move()));                  //Timer para mover el huevo
    vel->start(60);                                                    //Inicia el timer
}

void AtaqueR1::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();         //Crea la lista con los elementos a colisionar(huevos)
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){          //Ciclo que recorre la lista
        if (typeid(*(colliding_items[i])) == typeid(personaje)){       //Si un huevo colisiona con un tipo personaje
            gamme->scene->removeItem(this);                            //Remueva el huevo de la escena
            delete this;                                               //Elimine el puntero
            if(colliding_items[i]==gamme->perso){                      //Si el huevo colisiona con el personaje 1
                gamme->vid1->decrece1();                               //Reste 1 vida
                qDebug()<<"bye1";                                      //Imprime que se quito una vida
            } else if(colliding_items[i]==gamme->perso2){              //Si el huevo colisiona con el personaje 2
                gamme->vid2->decrece2();                               //Resta una vida
                qDebug()<<"bye2";                                      //Imprime que se quito una vida
            }
            return;                                                    //Retorne
        }
    }

    if(y()<=290) setPos(x(), y()+20);                                  //Si la posicion en y es menor o igual a 290 que sume 20.
    if(y()>291){                                                       //Si la posicion es mayor a 291 que empiece a rodar
        setPos(x()-20, y());                                           //Se mueva en x
        if(mover==0){                                                  //Si mover es igual aa 0
            setPixmap(QPixmap(":/Imagenes/HR2.png"));                  //Primera imagen del sprite
            mover=1;                                                   //Mover igual a 1
        }
        else if(mover==1){                                             //De lo contrario si mover es igual a 1
            setPixmap(QPixmap(":/Imagenes/HR3.png"));                  //Segunda imagen del sprite
            mover=2;                                                   //Mover igual a 2
        }
        else if(mover==2){                                             //Si mover es igual a 2
            setPixmap(QPixmap(":/Imagenes/HR4.png"));                  //Tercer imagen del sprite
            mover=3;                                                   //Mover igual a 3
        }
        else if(mover==3){                                             //Si mover es igual a 3
            setPixmap(QPixmap(":/Imagenes/HR5.png"));                  //Cuarta imagen del sprite
            mover=4;                                                   //Mover igual a 4
        }
        else if(mover==4){                                             //Si mover es igual a 4
            setPixmap(QPixmap(":/Imagenes/HR6.png"));                  //Quinta imagen del sprite
            mover=5;                                                   //Mover igual a 5
        }
        else if(mover==5){                                             //Si mover es igual a 5
            setPixmap(QPixmap(":/Imagenes/HR7.png"));                  //Sexta imagen del sprite
            mover=6;                                                   //Mover igual a 6
        }
        else if(mover==6){                                             //Si mover es igual a 6
            setPixmap(QPixmap(":/Imagenes/HR8.png"));                  //Septima imagen del sprite
            mover=0;                                                   //Reinicia el contado mover
        }
    }
    if(x()<0){                                                        //Si la posicion en x es menor a 0
        gamme->scene->removeItem(this);                               //Elimine el objeto de la escena
        delete this;                                                  //Elimine el puntero
    }
}
