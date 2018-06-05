#include "gameo.h"
#include "ui_gameo.h"
#include "menu2.h"
#include <iostream>
#include <QMessageBox>
#include "load.h"
#include <fstream>
#define RUTA_ARCHIVO "guardar.txt"

extern menu2 *menu;
using namespace std;

gameO::gameO(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameO)
{
    ui->setupUi(this);

    QString info;
    string var;//String para leer los datos del archivo
    int ent,contt=0;

    QFile file(RUTA_ARCHIVO);           //Objeto para manejar la lectura del archivo
    file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura
    info=file.readLine();

//    QFile file2(info);           //Objeto para manejar la lectura del archivo
//    file2.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura

//    while(!file2.eof()){
//        var=file.readLine();
//        ent = atoi(var.c_str());
//        if(contt==0) cont=ent;
//        else if(contt==1) p1=ent;
//        else if(contt==2) p2=ent;
//        contt++;
//    }

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,400); //se agrega el tamaño de la escena y la coordenada inicial
    ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //Quita las barras laterales
    ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WIDTH,HEIGHT);
    ui->view->setScene(scene); // colocar la escena que se desea visualizar
    qDebug()<<cont<<" "<<p1<<" "<<p2<<"DDDD";
    niveles();
    if(cont==0){
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/lvl1.jpeg"))); //Imagen nivel 1

        //musica de fondo
        musica->setMedia(QUrl("qrc:/sonido/lvl.mp3"));
        musica->play();
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
    TGame->start(3500);

    //Timer saltos
    QObject::connect(Tjump, SIGNAL(timeout()),perso,SLOT(jump())); //saltar player1
    QObject::connect(Tjump, SIGNAL(timeout()),perso2,SLOT(jump())); //saltar player2
    Tjump->start(45);

    //Vidas y puntaje
    vid1 = new vidas();
    vid2 = new vidas();
//    over = new QGraphicsTextItem();
//    over->setPlainText(QString(""));
//    over->setPos(300, 100);
//    over->setDefaultTextColor(Qt::white);
//    over->setFont(QFont("times",50));
//    scene->addItem(over);
}

void gameO::keyPressEvent(QKeyEvent *event)
{
    //personaje 1
    if (event->key() == Qt::Key_J){              //Movimiento izquierda
        perso->settBanLeft();                    //Levanta la bandera para moverse a la izquierda
        perso->setPixmap(QPixmap(":/Imagenes/p22"));
        qDebug() << "left";

    } else if (event->key() == Qt::Key_L){       //Movimiento izquierda
        perso->settBanRight();                   //Levanta la bandera para moverse a la izquierda
        perso->setPixmap(QPixmap(":/Imagenes/p2.png"));
        qDebug() << "right";

    } else if (event->key() == Qt::Key_Space){  //Disparo
        proyectil * bala1 = new proyectil();
        perso->setPixmap(QPixmap(":/Imagenes/disparo.png"));
        bala1->setPixmap(QPixmap(":/Imagenes/proyectil.png"));
        shoot->setMedia(QUrl("qrc:/sonido/Rasengan.mp3"));
        shoot->play();
        bala1->setPos(perso->x()+60,perso->y()+20); //Posicion del proyectil deacuerdo a la posicion del jugador
        scene->addItem(bala1);
        qDebug() << "bullet";
    }
    else if(event->key()==Qt::Key_I){
        perso->setBandera(); //Activa la bandera para saltar
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
        puntaje();

    } else if (event->key() == Qt::Key_F){
        bala = new proyectil();
        bala->setPixmap(QPixmap(":/Imagenes/gato.png"));
        piu->setMedia(QUrl("qrc:/sonido/rifle.mp3"));
        piu->play();
        bala->setPos(perso2->x()+50,perso2->y()+10);
        scene->addItem(bala);
        qDebug() << "bullet2";

    }
    else if(event->key()==Qt::Key_W){
        perso2->setBandera();
    }

    if(vid1->vj1<=0){
        piu->stop();
        shoot->stop();
        scene->removeItem(bala);
    }

    else flag=0;
    if(perso->pos().x()>800 && perso2->pos().x()>800) {
        cont++;
        niveles();
    }
}

void gameO::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_J){
        perso->resettBanLeft();
        perso->setPixmap(QPixmap(":/Imagenes/p11.png"));

        qDebug() << "left out";

    } else if (event->key() == Qt::Key_L){
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

void gameO::puntaje()
{
    p1+=10;
    p2+=10;
    ui->pun1->display(p1);
    ui->pun2->display(p2);
}

void gameO::cargar()
{
    string var; //nombre del archivo donde se guardan los nombres de las sesiones
    string datos;
    int ent,contt=0;

    ifstream loa;
    loa.open("guardar.txt",ios::in);
    getline(loa, var);

    ifstream cargar;
    cargar.open(var,ios::in);
    while(!cargar.eof()){
        getline(cargar, datos);
        ent = atoi(var.c_str());
        if(contt==0) cont=ent;
        else if(contt==1) p1=ent;
        else if(contt==2) p2=ent;
        contt++;
    }
}

void gameO::niveles()
{
    //_____________________NIVEL2__________________________________________________
    if(cont==1){
        TGame->stop();
        TGame1->stop();
        TGame2->stop();
        scene->removeItem(rect);
        scene->removeItem(perso);
        scene->removeItem(perso2);
        scene->clear();
        scene->setBackgroundBrush(QImage(":/Imagenes/lvl2.png"));
        scene->addItem(perso);
        scene->addItem(perso2);

        perso->setPixmap(QPixmap(":/Imagenes/p1.png"));
        perso->setHeight(HEIGHT);

        perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));
        perso2->setHeight(HEIGHT);
        perso2->setPos(20,280);
        perso->setPos(15, 280);
        perso->c=0;

        TGame->start(2500);
        TGame2->start(2800);
    }
    //_____________________NIVEL3__________________________________________________
    else if(cont==2){
        //limpia la escena, para los timers y elimina los punteros
        TGame->stop();
        TGame1->stop();
        TGame2->stop();
        scene->removeItem(rect);
        scene->removeItem(perso);
        scene->removeItem(perso2);
        scene->clear(); //limpia la escene

        //Crea la escena y los personajes
        scene->setBackgroundBrush(QImage(":/Imagenes/lvl5.gif"));
        scene->addItem(perso);
        scene->addItem(perso2);

        perso->setPixmap(QPixmap(":/Imagenes/p1.png"));
        perso->setHeight(HEIGHT);

        perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));
        perso2->setHeight(HEIGHT);
        perso2->setPos(20,280);
        perso->setPos(15, 280);
        perso->c=0;

        TGame->start(2500);
        TGame1->start(2600);
        TGame2->start(2800);

    //_____________________NIVEL4__________________________________________________
    }else if(cont==3){
        //limpia la escena, para los timers y elimina los punteros
        TGame->stop();
        TGame1->stop();
        TGame2->stop();
        scene->removeItem(rect);
        scene->removeItem(perso);
        scene->removeItem(perso2);
        scene->clear(); //limpia la escene

        //Crea la escena y los personajes
        scene->setBackgroundBrush(QImage(":/Imagenes/lvl.gif"));
        scene->addItem(perso);
        scene->addItem(perso2);

        perso->setPixmap(QPixmap(":/Imagenes/p1.png"));
        perso->setHeight(HEIGHT);

        perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));
        perso2->setHeight(HEIGHT);
        perso2->setPos(20,280);
        perso->setPos(15, 280);
        perso->c=0;

        TGame->start(2500);
        TGame1->start(2600);
        TGame2->start(2800);
    }
    //_____________________NIVEL FINAL__________________________________________________
    else if(cont==4){
        //limpia la escena, para los timers y elimina los punteros
        musica->stop();
        TGame->stop();
        TGame1->stop();
        TGame2->stop();
        scene->removeItem(rect);
        scene->removeItem(perso);
        scene->removeItem(perso2);
        scene->clear(); //limpia la escene

        //Crea la escena y los personajes
        scene->setBackgroundBrush(QImage(":/Imagenes/lvlu.png"));
        scene->addItem(perso);
        scene->addItem(perso2);

        perso->setPixmap(QPixmap(":/Imagenes/p1.png"));
        perso->setHeight(HEIGHT);

        perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));
        perso2->setHeight(HEIGHT);
        perso2->setPos(20,280);
        perso->setPos(15, 280);

        //crea el jefe final
        ramsey = new Ramsey;
        ramsey->setPos(620,15);
        scene->addItem(ramsey);
        music->setMedia(QUrl("qrc:/sonido/BossP.mp3"));
        music->play();
    }
}

gameO::~gameO()
{
    delete ui;
}

void gameO::on_save_clicked()
{
    ofstream save;
    save.open(menu->b,ios::out);
    save<<cont<<endl;
    save<<p1<<endl;
    save<<p2<<endl;
    save.close();
}

