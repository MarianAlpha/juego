#ifndef ALIENS_H
#define ALIENS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <typeinfo>

class aliens : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit aliens(QObject *parent = nullptr);
    QTimer * timer = new QTimer();
    int cont=0;
private:
    int contador=0;
signals:

public slots:
    void move();
};

#endif // ALIENS_H
