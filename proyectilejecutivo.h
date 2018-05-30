#ifndef PROYECTILEJECUTIVO_H
#define PROYECTILEJECUTIVO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <typeinfo>
#include <QDebug>
#include <QMediaPlayer>
#include "personaje.h"

class proyectilEjecutivo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    proyectilEjecutivo();
    QTimer *timer = new QTimer();
    int vida=5;
public slots:
    void move();//proyectiles personajes
};

#endif // PROYECTILEJECUTIVO_H
