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
    rect1->setPos(580,280);
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
    perso2->setHeight(HEIGHT);
    scene->addItem(perso2);

    //malo
//    villano *muymalo=new villano();
//    muymalo->setPos(500, 150);
    QObject::connect(TGame, SIGNAL(timeout()),perso,SLOT(generar()));
    TGame->start(2500);


    QObject::connect(Tjump, SIGNAL(timeout()),perso,SLOT(jump()));
    QObject::connect(Tjump, SIGNAL(timeout()),perso2,SLOT(jump()));
    Tjump->start(45);
    QObject::connect(nivel, SIGNAL(timeout()),perso2,SLOT(cambia()));
    nivel->start(30);

}

void game::keyPressEvent(QKeyEvent *event)
{
    //personaje 1
    if (event->key() == Qt::Key_Left){
        perso->settBanLeft();
        perso->setPixmap(QPixmap(":/Imagenes/p22"));
        qDebug() << "left";

    } else if (event->key() == Qt::Key_Right){
        perso->settBanRight();
        perso->setPixmap(QPixmap(":/Imagenes/p2.png"));
        qDebug() << "right";

    } else if (event->key() == Qt::Key_Space){
        proyectil * bala = new proyectil();
        perso->setPixmap(QPixmap(":/Imagenes/disparo.png"));
        bala->setPixmap(QPixmap(":/Imagenes/proyectil.png"));
        bala->setPos(perso->x()+60,perso->y()+20);
        scene->addItem(bala);
        qDebug() << "bullet";
    }
    else if(event->key()==Qt::Key_Up){
       perso->setBandera();
    }

//___________personaje 2___________________________

    else if (event->key() == Qt::Key_A){
        perso2->settBanLeft();
        perso2->setPixmap(QPixmap(":/Imagenes/pl23.png"));
        qDebug() << "left 2";

    } else if (event->key() == Qt::Key_D){
        perso2->settBanRight();
        perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));
        qDebug() << "right2";

    } else if (event->key() == Qt::Key_X){
        proyectil * bala = new proyectil();
        bala->setPixmap(QPixmap(":/Imagenes/gato.png"));
        bala->setPos(perso2->x()+50,perso2->y()+10);
        scene->addItem(bala);
        qDebug() << "bullet2";

    }
    else if(event->key()==Qt::Key_W){
       perso2->setBandera();
    }
}

void game::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        perso->resettBanLeft();
        perso->setPixmap(QPixmap(":/Imagenes/p11.png"));

        qDebug() << "left out";

    } else if (event->key() == Qt::Key_Right){
        perso->setPixmap(QPixmap(":/Imagenes/p1.png"));
        perso->resettBanRight();
        qDebug() << "right out";

    }else if (event->key() == Qt::Key_A){
        perso2->resettBanLeft();
        perso2->setPixmap(QPixmap(":/Imagenes/pl22.png"));
        qDebug() << "left 2 out";

    } else if (event->key() == Qt::Key_D){
        perso2->resettBanRight();
        perso2->setPixmap(QPixmap(":/Imagenes/pl11.png"));
        qDebug() << "right 2 out";
    }
}

void game::cambia()
{
    if(perso->pos().x()==900){
        setBackgroundBrush(QPixmap(":/Imagenes/lvl3.jpg"));
    }
}
