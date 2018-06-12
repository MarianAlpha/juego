#include "gameo.h"
#include "ui_gameo.h"
#include "menu2.h"
#include <iostream>
#include "mainwindow.h"
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

//    ifstream archivo1;                  //Define el archivo como lectura
//    archivo1.open(RUTA_ARCHIVO);        //Abre el archivo
//    string var;                         //Variable donde se guarda el nombre del archivo con los datos del jugador
//    while(!archivo1.eof()){             //Ciclo para recorrer el archivo
//        getline(archivo1, var);         //Guarda la primera linea del archivo en la variable var.
//    }
//    archivo1.close();                   //Cierra el archivo

//    ifstream archivo;                   //Define el archivo como lectura
//    archivo.open(var);                  //Abre el archivo del jugador
//    string line;                        //Variable donde se guardan los datos del archivo del jugador
//    int ent,contt=0;                    //Define el contador ent para guardar las variables convertidas en entero y contt para recorrer el archivo
//    if(!archivo.fail()){                //Si el archivo no falla
//        while(!archivo.eof()){          //Ciclo para recorrer el archivo (mientras no este al final)
//            getline(archivo, line);     //Obtengo una linea del archivo y la guardo en la variable line
//            ent = atoi(line.c_str());   //Convierto el dato de linea en un entero y lo guardo en la variable ent
//            if(contt==0) cont=ent;      //Si es la primera linea se le asignará cont(nivel)
//            else if(contt==1) p1=ent;   //De lo contrario si es la segunda linea sera el puntaje del jugador 1
//            else if(contt==2) p2=ent;   //De lo contrario si es la tercera linea sera el puntaje del jugador 2
//            contt++;                    //Aumenta el contador de las lineas
//        }
//    }
//    else{                               //Si el archivo falla
//        cont=0;                         //Cont sera igual a 0(nivel 1)
//        p1=0;                           //El puntaje del jugador 1 empezara en 0
//        p2=0;                           //El puntaje del jugador 2 empezara en 0
//    }
//    archivo.close();                    //Cierra el archivo

    scene = new QGraphicsScene();                                    //Crea escena
    scene->setSceneRect(0,0,1000,400);                               //se agrega el tamaño de la escena y la coordenada inicial
    ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  //Quita la barra de desplazamiento inferior
    ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);    //Quita la barra de desplazamineto lateral
    setFixedSize(WIDTH,HEIGHT);                                      //Define el ancho y el alto maximo del widget
    ui->view->setScene(scene);                                       // colocar la escena que se desea visualizar
    qDebug()<<cont<<" "<<p1<<" "<<p2;                                //Imprime el nivel, el puntaje de jugador 1 y el puntaje de jugador 2

    //musica de fondo
    musica->setMedia(QUrl("qrc:/sonido/lvl.mp3"));                   //Define la ruta del sonido del nivel 1
    musica->play();                                                  //Reproduce el sonido

    //Empieza en el nivel 1 por defecto
    if(cont==0){
        scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/lvl1.jpeg"))); //Fondo nivel 1

    }

    //player 1
    perso = new personaje();                          //Crea el personaje 1
    perso->setPixmap(QPixmap(":/Imagenes/p1.png"));   //Define la imagen del personaje 1
    perso->setPos(15,280) ;                           //Posicion inicial del personaje 1
    perso->setHeight(HEIGHT);                         //Altura maxima del salto
    scene->addItem(perso);                            //Añade el personaje 1 a la escena

    //player 2
    perso2 =new personaje();                             //Crea el personaje 2
    perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));   //Define la imagen del personaje 2
    perso2->setPos(20,280);                              //Posicion inicial del personaje 2
    perso2->setHeight(HEIGHT);                           //Altura maxima del salto
    scene->addItem(perso2);                              //Añade el personaje 2 a la escena

    //Villanos y trampas
    QObject::connect(TGame, SIGNAL(timeout()),perso,SLOT(generar()));    //Genera el Villano
    QObject::connect(TGame2, SIGNAL(timeout()),perso,SLOT(generar3()));  //Genera las palomas del lvl2
    QObject::connect(TGame1, SIGNAL(timeout()),perso,SLOT(generar2()));  //Genera la trampa del lvl3
    TGame->start(3500);                                                  //Inicia el timer que genera los villanos

    //Timer saltos
    QObject::connect(Tjump, SIGNAL(timeout()),perso,SLOT(jump()));      //saltar player1
    QObject::connect(Tjump, SIGNAL(timeout()),perso2,SLOT(jump()));     //saltar player2
    Tjump->start(45);                                                   //Inicia el timer para saltar

    //Vidas y puntaje
    vid1 = new vidas();           //Crea las vidas del jugador 1
    vid2 = new vidas();           //Crea las vidas del jugador 2
    niveles();                    //Llama el metodo niveles y comienza en el nivel cargado
}

void gameO::keyPressEvent(QKeyEvent *event)
{
    //___________personaje 1______________________________________________________________________________________

    if (event->key() == Qt::Key_J){                       //Definimos la tecla para el movimiento izquierda
        perso->settBanLeft();                             //Levanta la bandera para moverse a la izquierda
        perso->setPixmap(QPixmap(":/Imagenes/p22"));      //Define la imagen de movimiento a la izquierda
        qDebug() << "left";                               //Imprime que mueve hacia la izquierda

    } else if (event->key() == Qt::Key_L){                //Definimos la tecla para el movimiento Derecha
        perso->settBanRight();                            //Levanta la bandera para moverse a la Derecha
        perso->setPixmap(QPixmap(":/Imagenes/p2.png"));   //Define la imagen de movimiento a la Derecha
        qDebug() << "right";                              //Imprime que mueve hacia la Derecha

    } else if (event->key() == Qt::Key_H){                       //Definimos la tecla para disparar
        bala1 = new proyectil();                                 //Crea el tipo proyectil
        perso->setPixmap(QPixmap(":/Imagenes/disparo.png"));     //Cambia la imagen para cuando dispare
        bala1->setPixmap(QPixmap(":/Imagenes/proyectil.png"));   //Define la imagen del proyectil
        shoot->setMedia(QUrl("qrc:/sonido/rifle.mp3"));          //Define la ruta del sonido del proyectil
        shoot->play();                                           //Reproduce el sonido
        bala1->setPos(perso->x()+60,perso->y()+20);              //Posicion del proyectil deacuerdo a la posicion del jugador 1
        scene->addItem(bala1);                                   //Añade el proyectil a la escena
        qDebug() << "bullet";                                    //Imprimir que se generó un proyectil
    }
    else if(event->key()==Qt::Key_I){                            //Tecla para saltar
        perso->setBandera();                                     //Activa la bandera para saltar
    }

    //___________personaje 2______________________________________________________________________________________________

    else if (event->key() == Qt::Key_A){                         //Define la tecla para el movimiento izquierda
        perso2->settBanLeft();                                   //Levanta la bandera para el movimiento a la izquierda
        perso2->setPixmap(QPixmap(":/Imagenes/pl23.png"));       //Define la imagen para el movimiento a la izquierda
        qDebug() << "left 2";                                    //Imprime que el jugador 2 se movio hacia la izquierda

    } else if (event->key() == Qt::Key_D){                       //Define la tecla parael movimiento derecha
        perso2->settBanRight();                                  //Levanta la bandera para el movimiento a la derecha
        perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));       //Define la imagen para el movimiento a la derecha
        qDebug() << "right2";                                    //Imprime que el jugador 2 se movio hacia la derecha
        puntaje();

    } else if (event->key() == Qt::Key_F){                       //Definimos la tecla para disparar
        bala = new proyectil();                                  //Crea el tipo proyectil
        perso2->setPixmap(QPixmap(":/Imagenes/disparo2.png"));   //Cambia la imagen para disparar
        bala->setPixmap(QPixmap(":/Imagenes/gato.png"));         //Define la imagen del proyectil
        piu->setMedia(QUrl("qrc:/sonido/rifle.mp3"));            //Define la ruta del sonido del proyectil
        piu->play();                                             //Reproduce el sonido
        bala->setPos(perso2->x()+50,perso2->y()+10);             //Posicion del proyectil deacuerdo a la posicion del jugador 2
        scene->addItem(bala);                                    //Añade el proyectil a la escena
        qDebug() << "bullet2";                                   //Inprimer que se generó un proyectil

    }
    else if(event->key()==Qt::Key_W){                            //Tecla para saltal
        perso2->setBandera();                                    //Activa bandera para saltar
    }

    if(vid1->vj1<=0){                                           //Si las vidas del jugador 1 llegan a 0
        piu->stop();                                            //Detiene el sonido del disparo del jugador 2
        shoot->stop();                                          //Detiene el sonidodel disparo del juagdor 1
        scene->removeItem(bala);                                //Remueve de la escena el item bala
    }

    if(perso->pos().x()>800 && perso2->pos().x()>800 && perso->c>=5) {  //Si la posicion de ambos jugadores es mayor a 800 y han eliminado a 10 enemigos
        cont++;                                                          //El contador del nivel  aumentara
        niveles();                                                       //Llama el metodo niveles para generar el siguiente nivel
    }
}

void gameO::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_J){                                      //Si la tecla J esta presionada
        perso->resettBanLeft();                                          //Se reinicia la bandera de mover a la izquierda
        perso->setPixmap(QPixmap(":/Imagenes/p11.png"));                 //Se cambia la imagen para dar la ilucion de que camina
        qDebug() << "left out";                                          //Imprime que se dejo de mover

    } else if (event->key() == Qt::Key_L){                               //Si la tecla L esta presionada
        perso->resettBanRight();                                         //Se reinicia la bandera de mover a la derecha
        perso->setPixmap(QPixmap(":/Imagenes/p1.png"));                  //Se cambia la imagen para dar la ilucion de que camina
        qDebug() << "right out";                                         //Imprime que se dejo de mover

    }else if (event->key() == Qt::Key_A){                                //Si la tecla A esta presionada
        perso2->resettBanLeft();                                         //Se reinicia la bandera de mover a la izquierda
        perso2->setPixmap(QPixmap(":/Imagenes/pl22.png"));               //Se cambia la imagen para dar la ilucion de que camina
        qDebug() << "left 2 out";                                        //Imprime que se dejo de mover

    } else if (event->key() == Qt::Key_D){                               //Si la tecla D esta presionada
        perso2->resettBanRight();                                        //Se reinicia la bandera de mover a la derecha
        perso2->setPixmap(QPixmap(":/Imagenes/pl11.png"));               //Se cambia la imagen para dar la ilucion de que camina
        qDebug() << "right 2 out";                                       //Imprime que se dejo de mover
    }
}

void gameO::puntaje()
{
    p1+=10;                                                            //Cada vez que se llame el metodo puntaje, el score del jugador 1 aumentara el 10
    p2+=10;                                                            //Cada vez que se llame el metodo puntaje, el score del jugador 2 aumentara el 10
    ui->pun1->display(p1);                                             //Muestra el puntaje del jugador 1 en el display
    ui->pun2->display(p2);                                             //Muestra el puntaje del jugador 2 en el display
}

void gameO::niveles()
{
    //_____________________NIVEL2__________________________________________________________________________________
    if(cont==1){
        //Si cont es igual a 1
        TGame->stop();                                                  //Para el timer de los villanos
        TGame1->stop();                                                 //Para el timer de las trampas
        TGame2->stop();                                                 //Para el timer de las palomas
        scene->removeItem(perso);                                       //Quita el jugador 1 de la escena
        scene->removeItem(perso2);                                      //Quita el jugador 2 de la escena
        scene->clear();                                                 //Limpia la escena

        scene->setBackgroundBrush(QImage(":/Imagenes/lvl2.png"));       //Define el fondo del nivel 2
        scene->addItem(perso);                                          //Añade el personaje 1 a la escena
        scene->addItem(perso2);                                         //Añade el personaje 2 a la escena

        perso->setPixmap(QPixmap(":/Imagenes/p1.png"));                 //Define la imagen del personaje 1
        perso->setHeight(HEIGHT);                                       //Define la altula maxima

        perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));              //Define la imagen para el personaje 2
        perso2->setHeight(HEIGHT);                                      //Define la  altura maxima

        perso2->setPos(20,280);                                         //Define la posicion del personaje 2
        perso->setPos(15, 280);                                         //Define la posicion del personaje 1
        perso->c=0;                                                     //Reinicia el contador de los villanos

        TGame->start(2500);                                             //Inicia el timer de los villanos
        TGame2->start(2800);                                            //Inicia el timer de las palomas
    }
    //_____________________NIVEL3_______________________________________________________________________________
    else if(cont==2){                                                   //Si cont es igual a 2

        TGame->stop();                                                  //Para el timer de los villanos
        TGame1->stop();                                                 //Para el timer de las trampas
        TGame2->stop();                                                 //Para el timer de las palomas                                       //Quitar el jugador 1 de la escena
        scene->removeItem(perso);                                       //Quitar el jugador 1 de la escena
        scene->removeItem(perso2);                                      //Quitar el jugador 2 de la escena
        scene->clear();                                                 //Limpia la escena

        scene->setBackgroundBrush(QImage(":/Imagenes/lvl5.gif"));       //Define el fondo del nivel 3
        scene->addItem(perso);                                          //Añade el personaje 1 a la escena
        scene->addItem(perso2);                                         //Añade el personaje 2 a la escena

        perso->setPixmap(QPixmap(":/Imagenes/p1.png"));                 //Define la imagen del personaje 1
        perso->setHeight(HEIGHT);                                       //Define la altura maxima

        perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));              //Define la imagen del personaje 2
        perso2->setHeight(HEIGHT);                                      //Define la altura maxima

        perso2->setPos(20,280);                                         //Define la posicion del personaje 2
        perso->setPos(15, 280);                                         //Define la posicion del personaje 1
        perso->c=0;                                                     //Reinicia el contador de los villanos

        TGame->start(2500);                                             //Inicia el timer de los villanos
        TGame1->start(2600);                                            //Inicia el timer de las trampas
        TGame2->start(2800);                                            //Inicia el timer de las palomas

    //_____________________NIVEL4__________________________________________________________________________________
    }else if(cont==3){                                                  //Si cont es igual a 3

        TGame->stop();                                                  //Para el timer de los villanos
        TGame1->stop();                                                 //Para el timer de las trampas
        TGame2->stop();                                                 //Para el timer de las palomas
        scene->removeItem(perso);                                       //Quitar el personaje 1 de la escena
        scene->removeItem(perso2);                                      //Quitar el personaje 2 de la escena
        scene->clear();                                                 //Limpia la escena

        scene->setBackgroundBrush(QImage(":/Imagenes/lvl.gif"));        //Define el fondo del nivel 4
        scene->addItem(perso);                                          //Añade el personaje 1 a la escena
        scene->addItem(perso2);                                         //Añade el personaje 2 a la escena

        perso->setPixmap(QPixmap(":/Imagenes/p1.png"));                 //Define la imagen del ersonaje 1
        perso->setHeight(HEIGHT);                                       //Define la altura maxima

        perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));              //Define la imagen del personaje 2
        perso2->setHeight(HEIGHT);                                      //Define la altura maxima

        perso2->setPos(20,280);                                         //Define la posicion del personaje 2
        perso->setPos(15, 280);                                         //Define la posicion del personaje 1
        perso->c=0;                                                     //Reinicia el contador de los villanos

        TGame->start(2500);                                             //Inicia el timer de los villanos
        TGame1->start(2600);                                            //Inicia el timer de las trampas
        TGame2->start(2800);                                            //Inicia el timer de las palomas
    }
    //_____________________NIVEL FINAL__________________________________________________
    else if(cont==4){                                                   //Si cont es igual a 4

        musica->stop();                                                 //Para la musica de fondo
        TGame->stop();                                                  //Detiene el timer de los villanos
        TGame1->stop();                                                 //Detiene el timer de las trampas
        TGame2->stop();                                                 //Detiene el timer de las palomas
        scene->removeItem(perso);                                       //Remueve el personaje 1 de la escena
        scene->removeItem(perso2);                                      //Remueve el personaje 2 de la escena
        scene->clear();                                                 //limpia la escene

        scene->setBackgroundBrush(QImage(":/Imagenes/lvlu.png"));       //Define el fondo del nivel final
        scene->addItem(perso);                                          //Añade el personaje 1 a la escena
        scene->addItem(perso2);                                         //Añade el personaje 2 a la escena

        perso->setPixmap(QPixmap(":/Imagenes/p1.png"));                 //Define la imagen del personaje 1
        perso->setHeight(HEIGHT);                                       //Define la altura maxima

        perso2->setPixmap(QPixmap(":/Imagenes/pl12.png"));              //Define la imagen del personaje 2
        perso2->setHeight(HEIGHT);                                      //Define la altura maxima

        perso2->setPos(20,280);                                         //Define la posicion del personaje 2
        perso->setPos(15, 280);                                         //Define la posicion del personaje 1

        ramsey = new Ramsey;                                            //Crea la clase Ramsey que es el jefe final
        ramsey->setPos(620,15);                                         //Define la posicion del jefe final
        scene->addItem(ramsey);                                         //Añade a Ramsey a la escena
        music->setMedia(QUrl("qrc:/sonido/BossP.mp3"));                 //Define la ruta de la musica de fondo del nivel
        music->play();                                                  //Reproduce la musica
    }
}

gameO::~gameO()
{
    delete ui;                                                        //Destrucctor del juego
}

void gameO::on_save_clicked()
{
    ofstream save;                                                   //Define el archivo en modo de escritura
    save.open(menu->b,ios::out);                                     //Abre el archivo
    save<<cont<<endl;                                                //Escribe el nivel actual
    save<<p1<<endl;                                                  //Escriber el puntaje del jugador 1
    save<<p2<<endl;                                                  //Escribe el puntaje del jugador 2
    save.close();                                                    //Cierra el archivo
}


void gameO::on_save_2_clicked()
{
    MainWindow *menu = new MainWindow();                            //Crea una ventana main manu
    menu->show();                                                   //Muestra la ventana
    music->stop();                                                  //Detiene la musica
    close();                                                        //Cierra la ventana
}
