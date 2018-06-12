#include "proyectilalien.h"
#include "gameo.h"

extern gameO *gamme;

ProyectilAlien::ProyectilAlien()
{
    setPixmap(QPixmap(":/Imagenes/huevo.png"));                              //Define la imagen del huevo
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));                     //Timer de movimiento
    timer->start(50);                                                        //Inicia el timer
}

void ProyectilAlien::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();              //Lista de huevos
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){               //Ciclo que recorre la lista
        if (typeid(*(colliding_items[i])) == typeid(personaje)){            //Si colisiona con un personaje
            gamme->scene->removeItem(this);                                 //Elimine el huevo
            if(colliding_items[i]==gamme->perso){                           //Si colisiona con el personaje 1
                gamme->vid1->decrece1();                                    //Quite 1 vida
                qDebug()<<"bye1";
            } else if(colliding_items[i]==gamme->perso2){                   //Si colisiona con el personaje 2
                gamme->vid2->decrece2();                                    //Reste una vida
                qDebug()<<"bye2";
            }
            return;
        }
    }

    if(y()<380) {                                                          //Si y es menos a 380
        setPos(x(), y()+20);                                               //Se mueva hacia abajo
        if(y() >280 && y()<380) setPixmap(QPixmap(":/Imagenes/boom.png")); //Explota el huevo
        explo->setMedia(QUrl("qrc:/sonido/explosion.mp3"));                //Sonido de explosion
        explo->play();                                                     //Reproduce el sonido
    }
    if(y() >=340){                                                         //Si y es mayor a 340
        setPos(x(),y());                                                   //Deje se moverse
        gamme->scene->removeItem(this);                                    //Elimina el huevo de la escena
        delete this;
    }
}
