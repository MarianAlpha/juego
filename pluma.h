#ifndef PLUMA_H
#define PLUMA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <typeinfo>
#include "QTimer"

class pluma : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit pluma(QObject *parent = nullptr);
    QTimer *plum = new QTimer();
    int mover=0;
signals:

public slots:
    void move();
};

#endif // PLUMA_H
