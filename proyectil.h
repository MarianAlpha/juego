#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <typeinfo>

class proyectil:public QObject, public QGraphicsPixmapItem
{ Q_OBJECT
public:
    proyectil();
public slots:
    void move();
};

#endif // PROYECTIL_H
