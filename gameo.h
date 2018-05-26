#ifndef GAMEO_H
#define GAMEO_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QImage>
#include <QMediaPlayer>
#include <personaje.h>
#include <QKeyEvent>
#include "proyectil.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include "villano.h"

#define WIDTH 1000
#define HEIGHT 400

namespace Ui {
class gameO;
}

class gameO : public QWidget
{
    Q_OBJECT

public:
    explicit gameO(QWidget *parent = 0);
    //Media and pictures
    QMediaPlayer *music=new QMediaPlayer();
    QGraphicsScene *scene;
    QGraphicsLineItem *fin;
    QGraphicsPixmapItem *rect = new QGraphicsPixmapItem();
    QGraphicsPixmapItem *rect1 = new QGraphicsPixmapItem();

    //Timers
    QTimer *Tjump = new QTimer();
    QTimer *TGame = new QTimer();
    QTimer *TGame1 = new QTimer();
    QTimer *TGame2 = new QTimer();
    QTimer *TShoot = new QTimer();
    QTimer *timercambio = new QTimer();

    //Class
    personaje * perso2;
    personaje *perso;

    //Metodos y atributos
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void setHeight(int w);
    int vidas=3,cont=0;
    int cambio=0;
    ~gameO();

private:
    Ui::gameO *ui;
};

#endif // GAMEO_H
