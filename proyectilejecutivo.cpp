#include "proyectilejecutivo.h"
#include "gameo.h"


extern gameO *gamme;

proyectilEjecutivo::proyectilEjecutivo()
{
    setPixmap(QPixmap(":/Imagenes/gato.png"));
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);

}


void proyectilEjecutivo::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->vid->decrece();
            gamme->scene->removeItem(this);
            return;
        }
    }

    setPos(x()-20, y());
    if (x() < 0){
        gamme->scene->removeItem(this);
        delete this;
    }
}

