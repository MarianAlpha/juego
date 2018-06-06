#ifndef RAMSEY_H
#define RAMSEY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QGraphicsScene>

class Ramsey : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Ramsey(QObject *parent = nullptr);
    QTimer * timer = new QTimer();
    QTimer * plumas = new QTimer();
    QTimer *huevos = new QTimer();
    QGraphicsTextItem *winn;
    QMediaPlayer *musicaF = new QMediaPlayer();
    int cont=0,cont1=0;
    int numplumas=0;
    int flag=0;
    int head=0;
    int vidaR=100;
    void win();
signals:

public slots:
    void move();
    void huevo();
    void pluma1();
};

#endif // RAMSEY_H
