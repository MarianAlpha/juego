#include "menu1.h"
#include "ui_menu1.h"
#include "funciones.h"

menu1::menu1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu1)
{
    ui->setupUi(this);
    player =new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/menu1.mp3"));
    player->play();
}

menu1::~menu1()
{
    delete ui;
}

void menu1::on_newgame_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/boton.mp3"));
    player->play();
    delay(3);
    menu2*menu1 = new menu2;
    menu1->show();
    close();
}

void menu1::on_loadgame_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/boton.mp3"));
    player->play();
}
