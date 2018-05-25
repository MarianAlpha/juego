#include "game.h"

game::game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,400); //se agrega el tamaño de la escena y la coordenada inicial
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //Quita las barras laterales
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WIDTH,HEIGHT);

    if(cont==0){
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/lvl1.jpeg"))); //Imagen nivel 1
        setScene(scene); // colocar la escena que se desea visualizar


        //QGraphicsPixmapItem *rect = new QGraphicsPixmapItem(); //ladrillo
        rect->setPixmap(QPixmap(":/Imagenes/ladrillo.jpg"));
        rect->setPos(400,140);
        scene->addItem(rect);

        //QGraphicsPixmapItem *rect1 = new QGraphicsPixmapItem(); //barricada
        rect1->setPixmap(QPixmap(":/Imagenes/barricada.png"));
        rect1->setPos(580,280);
        scene->addItem(rect1);

        //musica de fondo
        music->setMedia(QUrl("qrc:/sonido/fondolvl1.mp3"));
        music->play();
    }
    //player 1
    perso = new personaje();
    perso->setPixmap(QPixmap(":/Imagenes/p1.png"));
    perso->setPos(15,280) ; // posicion inicial del jugador //
    perso->setHeight(HEIGHT);
    scene->addItem(perso);

    //player 2
    perso2 =new personaje();
    perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));
    perso2->setPos(20,280);
    perso2->setHeight(HEIGHT);
    scene->addItem(perso2);

    //Villanos y trampas
    QObject::connect(TGame, SIGNAL(timeout()),perso,SLOT(generar()));//Genera el Villano
    QObject::connect(TGame2, SIGNAL(timeout()),perso,SLOT(generar3()));//Genera el alien del lvl2
    QObject::connect(TGame1, SIGNAL(timeout()),perso,SLOT(generar2()));//Genera la trampa del lvl3
    TGame->start(2500);


    QObject::connect(Tjump, SIGNAL(timeout()),perso,SLOT(jump())); //saltar player1
    QObject::connect(Tjump, SIGNAL(timeout()),perso2,SLOT(jump())); //saltar player2
    Tjump->start(45);

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
    //_____________________NIVEL2__________________________________________________
    if(perso->pos().x()>800 && perso2->pos().x()>800) {
        cont++;
        if(cont==1){
            scene->setBackgroundBrush(QImage(":/Imagenes/lvl2.png"));
            perso->setPos(15, 280);
            perso2->setPos(20, 280);
            scene->removeItem(rect);
            perso->c=0;
            TGame2->start(2800);
        }
        //_____________________NIVEL3__________________________________________________
        else if(cont==2){
            scene->setBackgroundBrush(QImage(":/Imagenes/lvl5.gif"));
            perso->setPos(15, 280);
            perso2->setPos(20, 280);
            perso->c=0;
            TGame1->start(2500);
        }
        //_____________________NIVEL4__________________________________________________
        else if(cont==3){
            scene->setBackgroundBrush(QImage(":/Imagenes/lvl.gif"));
            perso->setPos(15, 280);
            perso2->setPos(20, 280);
            perso->c=0;
        }
        //_____________________NIVEL FINAL__________________________________________________
        else if(cont==4){
            scene->setBackgroundBrush(QImage(":/Imagenes/lvlu.png"));
            perso->setPos(15, 280);
            perso2->setPos(20, 280);
            TGame1->stop();
            TGame2->stop();
        }
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
