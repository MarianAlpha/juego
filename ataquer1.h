#ifndef ATAQUER1_H
#define ATAQUER1_H

#include <QObject>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <typeinfo>
#include "QTimer"

class AtaqueR1 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit AtaqueR1(QObject *parent = nullptr);
    QTimer *vel = new QTimer();
    int mover=0;
signals:

public slots:
    void move();
};

#endif // ATAQUER1_H
