#include "proyectilalien.h"
#include "gameo.h"

extern gameO *gamme;

ProyectilAlien::ProyectilAlien()
{
    setPixmap(QPixmap(":/Imagenes/huevo.png"));
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void ProyectilAlien::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->scene->removeItem(this);
            delete this;
            return;
        }
    }

    if(y()<380) {
        setPos(x(), y()+20);
        if(y() >280 && y()<380) setPixmap(QPixmap(":/Imagenes/boom.png")); //Explota el huevo
    }
    if(y() >=340){
        setPos(x(),y());
        gamme->scene->removeItem(this);
        delete this;
    }
}
