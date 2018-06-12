#include "pluma.h"
#include "personaje.h"
#include "gameo.h"

extern gameO *gamme;

pluma::pluma(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/Imagenes/pluma.png"));                            //Define la imagen de la pluma
    connect(plum,SIGNAL(timeout()),this,SLOT(move()));                     //Timer de movimiento
    plum->start(20);                                                       //Empieza el timer
}

void pluma::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();             //Crea una lista de plumas
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){              //Ciclo que recorre la lista
        if (typeid(*(colliding_items[i])) == typeid(personaje)){           //Si un elemto de la lista colisiona con un personaje
            gamme->scene->removeItem(this);                                //Elimine el objeto
            if(colliding_items[i]==gamme->perso){                          //Si el personaje era el jugador 1
                gamme->vid1->decrece1();                                   //Reste una vida
                qDebug()<<"bye1";                                          //Imprime que se le quito una vida
            } else if(colliding_items[i]==gamme->perso2){                  //Si el personaje era el jugador 2
                gamme->vid2->decrece2();                                   //Reste una vida
                qDebug()<<"bye2";                                          //Imprime que se quito una vida
            }
            return;
        }
    }
    setPos(x(),y()+20);                                                    //se mueva 20 en y (hacia abajo)
    if(y()>300) {                                                          //Si la posicion en y es mayor a 300
        gamme->scene->removeItem(this);                                    //Elimine el item
        delete this;                                                       //Libere la memoria
    }
}
