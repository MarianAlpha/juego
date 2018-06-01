#include "menu1.h"
#include "mainwindow.h"
#include "ui_menu1.h"
#include "funciones.h"

menu2 *menu;

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
    delay(2);
    menu = new menu2;
    menu->show();
    close();
}

void menu1::on_loadgame_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/boton.mp3"));
    player->play();
}

void menu1::on_return_3_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/boton.mp3"));
    player->play();
    delay(2);
    MainWindow*menu1 = new MainWindow;
    menu1->show();
    close();
}
