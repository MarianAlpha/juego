#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QGraphicsScene>


class personaje: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    explicit personaje(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
    //void keyReleaseEvent(QKeyEvent *event1);
    void setHeight(int w);
private:
    QMediaPlayer *music=new QMediaPlayer();
    personaje *p2;
    int bandera;
    int bandera2,cont=0;
    float delta;
    int height;

signals:

public slots:
    void jump();
};

#endif // PERSONAJE_H
