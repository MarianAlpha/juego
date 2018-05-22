#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <typeinfo>

class proyectil:public QObject, public QGraphicsPixmapItem
{ Q_OBJECT
public:
    proyectil();
    QTimer *timer= new QTimer();
public slots:
    void move();
};

#endif // PROYECTIL_H
