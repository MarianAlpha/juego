#ifndef PERSONAJE_H
#define PERSONAJE_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <villano.h>

class personaje: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    explicit personaje(QGraphicsItem *parent = nullptr);
    void settBanLeft();
    void settBanRight();
    void resettBanLeft();
    void resettBanRight();
    void setBandera();
    void resetBandera();
    int bandera=0,c=0;
    villano * enemigo;

private:
    QMediaPlayer *music=new QMediaPlayer();
    int ban_left;
    int ban_right;
    int height;
    float delta = 0,delta2;

signals:

public slots:

    void move_right();
    void move_left();
    void generar();
    void generar2();
    void generar3();
    void jump();
    void setHeight(int);
};


#endif // PERSONAJE_H
