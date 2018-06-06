#include "proyectilejecutivo.h"
#include "gameo.h"


extern gameO *gamme;

proyectilEjecutivo::proyectilEjecutivo()
{
    setPixmap(QPixmap(":/Imagenes/maiz.png"));
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);

}


void proyectilEjecutivo::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->scene->removeItem(this);
            if(colliding_items[i]==gamme->perso){
                gamme->vid1->decrece1();
                qDebug()<<"bye1";
            } else if(colliding_items[i]==gamme->perso2){
                gamme->vid2->decrece2();
                qDebug()<<"bye2";
            }
            gamme->vt=(gamme->vid1->vj1)*10+gamme->vid2->vj2;
            qDebug()<<gamme->vt<<"zzzzzzz";
            return;
        }
    }

    setPos(x()-20, y());
    if (x() < 0){
        gamme->scene->removeItem(this);
        delete this;
    }
}

