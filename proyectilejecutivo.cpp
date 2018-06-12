#include "proyectilejecutivo.h"
#include "gameo.h"


extern gameO *gamme;

proyectilEjecutivo::proyectilEjecutivo()
{
    setPixmap(QPixmap(":/Imagenes/maiz.png"));                      //Define la imagen del proyectil de los soldador aravicos
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));            //Timer de movimiento
    timer->start(50);                                               //Inicia el timer

}


void proyectilEjecutivo::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();     //Lista con los elementos que colisionan
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){      //Ciclo que recorre la lista
        if (typeid(*(colliding_items[i])) == typeid(personaje)){   //Si el proyectil colisiona con el personaje
            gamme->scene->removeItem(this);                        //Elimina el proyectil de la escena
            if(colliding_items[i]==gamme->perso){                  //Si colisiona con el jugador 1
                gamme->vid1->decrece1();                           //Le quita una vida
                qDebug()<<"bye1";
            } else if(colliding_items[i]==gamme->perso2){          //Si colisiona con el juagador 2
                gamme->vid2->decrece2();                           //Le quita una vida
                qDebug()<<"bye2";
            }
            gamme->vt=(gamme->vid1->vj1)*10+gamme->vid2->vj2;      //Conatenas las vidas totales para enviarle el dato al arduino
            qDebug()<<gamme->vt<<"zzzzzzz";                        //Las imprime
            return;
        }
    }

    setPos(x()-20, y());                                           //Mueve la bala en x hacia la izquierda
    if (x() < 0){                                                  //Si la posicion de la bala en menor a 0
        gamme->scene->removeItem(this);                            //Elimina de la escena
        delete this;                                               //Libera la memoria
    }
}

