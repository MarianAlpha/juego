#ifndef GAMEO_H
#define GAMEO_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QImage>
#include <QMediaPlayer>
#include <QFile>
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
    QTimer *Tcaer = new QTimer();
    QTimer *timercambio = new QTimer();
    QTimer *puntajes = new QTimer();

    //Class
    personaje *perso2;
    personaje *perso;
    Ramsey *ramsey;
    proyectil *bala;
    proyectil *bala1;
    vidas *vid1;
    vidas *vid2;

    //Metodos y atributos
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void setHeight(int w);
    void puntaje();
    void niveles();
    int cont;
    int vt;
    int p1, p2;
    int cambio=0;
    int flag=0;
    ~gameO();

private slots:
    void on_save_clicked();

private:
    Ui::gameO *ui;
};

#endif // GAMEO_H
