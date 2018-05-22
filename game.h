#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QImage>
#include <QMediaPlayer>
#include "personaje.h"
#include <QKeyEvent>
#include "proyectil.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include "villano.h"


#define WIDTH 1000
#define HEIGHT 400

class game: public QGraphicsView
{
public:
    game();
    personaje *perso;
    personaje * perso2;
    int cambio=0;
    QGraphicsScene *scene;
    QMediaPlayer *music=new QMediaPlayer();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void setHeight(int w);
    QTimer *Tjump= new QTimer();
    QTimer * timercambio= new QTimer();
    QTimer *TGame= new QTimer();
    QGraphicsView *ver;
    int vidas=3;
};

#endif // GAME_H
