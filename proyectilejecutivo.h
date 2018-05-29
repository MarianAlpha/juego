#ifndef PROYECTILEJECUTIVO_H
#define PROYECTILEJECUTIVO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <typeinfo>
#include <QDebug>
#include "vidas.h"
#include "personaje.h"

class proyectilEjecutivo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    proyectilEjecutivo();
    vidas *vid = new vidas();
    QTimer *timer,*timerP= new QTimer();


    void vidas1();
    bool flag = false;
public slots:
    void move();//proyectiles personajes
};

#endif // PROYECTILEJECUTIVO_H
