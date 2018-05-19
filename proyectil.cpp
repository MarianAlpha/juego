#include "proyectil.h"
#include <QTimer>

proyectil::proyectil()
{
    setPixmap(QPixmap(":/Imagenes/proyectil.png"));
    QTimer *timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void proyectil::move()
{
    setPos(x()+10, y());
}
