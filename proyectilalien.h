#ifndef PROYECTILALIEN_H
#define PROYECTILALIEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <typeinfo>
#include "personaje.h"

class ProyectilAlien : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ProyectilAlien();
    QTimer *timer= new QTimer();
public slots:
    void move();//proyectiles personajes
};

#endif // PROYECTILALIEN_H
