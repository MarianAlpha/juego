#ifndef VILLANO_H
#define VILLANO_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <typeinfo>


class villano: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    explicit villano(QGraphicsItem *parent = nullptr);
    QTimer * timer = new QTimer();
    QTimer *pum = new QTimer();
    int cont=0;
private:
    int contador=0;
signals:

public slots:
    void move();
    void shoot();
};
#endif // VILLANO_H
