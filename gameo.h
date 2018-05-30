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
#include "ramsey.h"
#include "proyectil.h"
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include "villano.h"
#include "vidas.h"

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
    QMediaPlayer *music = new QMediaPlayer();
    QMediaPlayer *musica = new QMediaPlayer();
    QMediaPlayer *shoot =new QMediaPlayer();
    QMediaPlayer *piu = new QMediaPlayer();
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
    QTimer *puntajes = new QTimer();

    //Class
    personaje * perso2;
//    QGraphicsTextItem *over;
    personaje *perso;
    Ramsey *ramsey;
    proyectil * bala;
    vidas *vid;

    //Metodos y atributos
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void setHeight(int w);
    void limpiar();
    void puntaje();
    int cont=0;
    int p1=0, p2=0;
    int cambio=0;
    ~gameO();

private:
    Ui::gameO *ui;
};

#endif // GAMEO_H
