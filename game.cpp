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
    //perso->setFlag(QGraphicsItem::ItemIsFocusable); // primero le decimos que rect pueda ser enfoncable
    // enfoncar el item (sólo el que está enfoncado es el que responde a eventos de teclado)
    //perso->setFocus(); // se coloca el foco en rect
    perso->setPos(15,280) ; // posicion inicial del jugador //
    perso->setHeight(HEIGHT);
    scene->addItem(perso);

    perso2 =new personaje();
    perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));
    perso2->setPos(20,280);
    scene->addItem(perso2);

    //malo
    QObject::connect(TGame, SIGNAL(timeout()),perso,SLOT(generar()));
    TGame->start(2500);


    QObject::connect(Tjump, SIGNAL(timeout()),perso,SLOT(jump()));
    Tjump->start(45);
    //QObject::connect(Tjump, SIGNAL(timeout()),perso2,SLOT(jump()));
    //Tjump->start(45);
}

void game::keyPressEvent(QKeyEvent *event)
{
    //personaje 1
    if (event->key() == Qt::Key_Left){
        perso->settBanLeft();
        qDebug() << "left";

    } else if (event->key() == Qt::Key_Right){
        perso->settBanRight();
        qDebug() << "right";

    } else if (event->key() == Qt::Key_Space){
        proyectil * bala = new proyectil();
        bala->setPos(perso->x(),perso->y());
        scene->addItem(bala);
        qDebug() << "bullet";
    }
    if(event->key()==Qt::Key_Up){
       perso->setBandera();
    }

//___________personaje 2___________________________

    else if (event->key() == Qt::Key_A){
        //ban_left = 1;
        perso2->settBanLeft();
        qDebug() << "left 2";

    } else if (event->key() == Qt::Key_D){
        //ban_right = 1;
        perso2->settBanRight();
        qDebug() << "right2";

    } else if (event->key() == Qt::Key_X){
        proyectil * bala = new proyectil();
        bala->setPos(perso2->x(),perso2->y());
        scene->addItem(bala);
        qDebug() << "bullet2";

    }
}

void game::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        perso->resettBanLeft();
        qDebug() << "left out";

    } else if (event->key() == Qt::Key_Right){
        perso->resettBanRight();
        qDebug() << "right out";

    }else if (event->key() == Qt::Key_A){
        perso2->resettBanLeft();
        qDebug() << "left 2 out";

    } else if (event->key() == Qt::Key_D){
        perso2->resettBanRight();
        qDebug() << "right 2 out";
    }
    else if (event->key()==Qt::Key_Up){
        perso->resetBandera();
    }
}
