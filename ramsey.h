#ifndef RAMSEY_H
#define RAMSEY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsScene>

class Ramsey : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Ramsey(QObject *parent = nullptr);
    QTimer * timer = new QTimer();
    QTimer *huevos = new QTimer();
    int cont=0;
    int head=0;
    int vidaR=20;
    void win();
signals:

public slots:
    void move();
    void huevo();
};

#endif // RAMSEY_H
