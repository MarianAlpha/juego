#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QImage>
#include <QMediaPlayer>
#include <personaje.h>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QWidget>

#define WIDTH 1000
#define HEIGHT 400

class Game: public QGraphicsView // al heredaar de view. es un widget
{
public:
    Game();
    personaje *perso;
    QMediaPlayer *music=new QMediaPlayer();
    QGraphicsScene * scene;
    QTimer *Tjump= new QTimer();
    QGraphicsView *ver;
};

#endif // GAME_H
