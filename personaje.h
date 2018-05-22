#ifndef PERSONAJE_H
#define PERSONAJE_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <fstream>

class personaje: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    explicit personaje(QGraphicsItem *parent = nullptr);
    //void keyPressEvent(QKeyEvent * event);
    //void keyReleaseEvent(QKeyEvent *event1);
    //void setHeight(int w);
    void settBanLeft();
    void settBanRight();
    void resettBanLeft();
    void resettBanRight();
    void setBandera();
    void resetBandera();
    int bandera=0;

private:
    QMediaPlayer *music=new QMediaPlayer();
    int ban_left;
    int ban_right;
    int cont=0;
    int height;
    float delta = 0;

signals:

public slots:

    void move_right();
    void move_left();
    void generar();
    void jump();
    void setHeight(int);
};


#endif // PERSONAJE_H
