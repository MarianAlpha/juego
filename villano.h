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
private:
    int cont=0;
signals:

public slots:
    void move();
};
#endif // VILLANO_H
