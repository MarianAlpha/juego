#include "comic.h"
#include "ui_comic.h"
#include "funciones.h"
#include "gameo.h"
#include "load.h"

gameO *gamme;

comic::comic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::comic)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();                                        //Crea la escena
    scene->setSceneRect(0,0,900,506);                                    //se agrega el tamaño de la escena y la coordenada inicial
    ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);      //Quita la barra de desplazamiento inferior
    ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);        //Quita la barra de desplazamiento lateral
    setFixedSize(900,506);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/comic1.png")));  //Primera parte del comic
    ui->view->setScene(scene);                                           // colocar la escena que se desea visualizar

}

comic::~comic()
{
    delete ui;                                                          //Destructor del juego
}

void comic::on_pushButton_clicked()
{

    nextt++;                                                                              //Contador para pasar el comic
    if(nextt==1)  scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/comic2.png")));     //Tercera parte del comic
    if(nextt==2)  scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/comic3.png")));     //Segunda parte del comic
    if(nextt==3)  scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/comic4.png")));     //Cuarta parte del comic
    if(nextt==4)  scene->setForegroundBrush(QBrush(QImage(":/Imagenes/tutorial.png")));    //Tutorial
    if(nextt==5){
        gamme =new gameO();                                                               //Crea el juego
        gamme->show();                                                                    //Lo muestra
        close();                                                                          //Cierra este widget
    }
}
