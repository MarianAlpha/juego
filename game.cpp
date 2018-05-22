#include "game.h"

game::game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,400); //se agrega el tamaño de la escena y la coordenada inicial
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/lvl1.jpeg")));
    setScene(scene); // colocar la escena que se desea visualizar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WIDTH,HEIGHT);


    QGraphicsPixmapItem *rect = new QGraphicsPixmapItem();
    rect->setPixmap(QPixmap(":/Imagenes/ladrillo.jpg"));
    rect->setPos(400,140);
    scene->addItem(rect);

    QGraphicsPixmapItem *rect1 = new QGraphicsPixmapItem();
    rect1->setPixmap(QPixmap(":/Imagenes/barricada.png"));
    rect1->setPos(780,280);
    scene->addItem(rect1);

    //musica de fondo
    music->setMedia(QUrl("qrc:/sonido/fondolvl1.mp3"));
    music->play();

    //personaje 1
    perso = new personaje();
    perso->setPixmap(QPixmap(":/Imagenes/p1.png"));
    perso->setFlag(QGraphicsItem::ItemIsFocusable); // primero le decimos que rect pueda ser enfoncable
    // enfoncar el item (sólo el que está enfoncado es el que responde a eventos de teclado)
    perso->setFocus(); // se coloca el foco en rect
    perso->setPos(15,280) ; // posicion inicial del jugador //
    perso->setHeight(HEIGHT);
    scene->addItem(perso);


    //malo
    QObject::connect(TGame, SIGNAL(timeout()),perso,SLOT(generar()));
    TGame->start(2500);


    QObject::connect(Tjump, SIGNAL(timeout()),perso,SLOT(jump()));
    Tjump->start(45);
}
