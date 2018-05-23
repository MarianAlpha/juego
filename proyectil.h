#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <typeinfo>
#include "personaje.h"

class proyectil:public QObject, public QGraphicsPixmapItem
{ Q_OBJECT
public:
    proyectil();
    QTimer *timer= new QTimer();
    int bye; //contador de malos
public slots:
    void move();//proyectiles personajes
};

#endif // PROYECTIL_H
