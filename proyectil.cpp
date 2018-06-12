#include "proyectil.h"
#include <villano.h>
#include "ramsey.h"
#include  "gameo.h"

extern gameO *gamme;

proyectil::proyectil()
{
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));          //Timer de movimiento
    timer->start(50);                                             //Inicia el timer
}

void proyectil::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();   //Crea una lista de proyectiles
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){    //Ciclo que recorre la lista
        if (typeid(*(colliding_items[i])) == typeid(villano)){   //Si el proyectil colisiona con un tipo villano
            scene()->removeItem(colliding_items[i]);             //Elimine el villano
            scene()->removeItem(this);                           //Elimine el proyctil
            gamme->p1=gamme->p1+100;                             //Sume 100 a puntaje del player 1
            gamme->p2=gamme->p2+100;                             //Sume 100 a puntaje del player 2
            delete colliding_items[i];                           //Libera la memoria
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Ramsey)){   //Si el proyectil colisiona con Ramsey                                                //
            gamme->p1=gamme->p1+200;                                 //Le sume 200 al puntaje de p1
            gamme->p2=gamme->p2+200;                                 //Le sume 200 al puntaje de p2
            gamme->ramsey->win();                                    //Le reste vidas a Ramsey
            qDebug()<<"!!!!!!!!!!!"<<gamme->ramsey->vidaR;           //Muestra las vidas que le quedan a ramsey
            scene()->removeItem(this);                               //Elimina la bala de la escena
            delete this;                                             //Libera la memoria
            return;
        }
    }


    setPos(x()+20, y());                                             //El proyectil se mueve en x
    if (x() < 0){                                                    //Si la posicion en x es menor a 0
        scene()->removeItem(this);                                   //Elimine la bala de la escena
        delete this;                                                 //Libere memoria
    }
    if(gamme->vid1->vj1<=0){                                         //Si las vidas son menores o igualles a 0
        timer->stop();                                               //Pare el timer
    }
}
