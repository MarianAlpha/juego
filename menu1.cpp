#include "menu1.h"
#include "load.h"
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
    player->setMedia(QUrl("qrc:/sonido/menu1.mp3"));
    player->play();
}

menu1::~menu1()
{
    delete ui;
}

void menu1::on_newgame_clicked()
{
    player->setMedia(QUrl("qrc:/sonido/boton.mp3"));
    player->play();
    menu = new menu2;
    menu->show();
    close();
}

void menu1::on_loadgame_clicked()
{
    player->setMedia(QUrl("qrc:/sonido/boton.mp3"));
    player->play();
    load *loadd = new load();
    loadd->show();
    close();

}

void menu1::on_return_3_clicked()
{
    player->setMedia(QUrl("qrc:/sonido/boton.mp3"));
    player->play();
    delay(2);
    MainWindow*menu1 = new MainWindow;
    menu1->show();
    close();
}
