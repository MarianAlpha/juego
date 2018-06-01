#include "comic.h"
#include "ui_comic.h"
#include "funciones.h"
#include "gameo.h"

gameO *gamme;

comic::comic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::comic)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,900,506); //se agrega el tamaño de la escena y la coordenada inicial
    ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //Quita las barras laterales
    ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,506);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/comic1.png"))); //Imagen nivel 1
    ui->view->setScene(scene); // colocar la escena que se desea visualizar

}

comic::~comic()
{
    delete ui;
}

void comic::on_pushButton_clicked()
{
    nextt++;
    if(nextt==1)  scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/comic2.png")));
    if(nextt==2)  scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/comic3.png")));
    if(nextt==3){
    gamme =new gameO();
    gamme->show();
    close();
    }
}
