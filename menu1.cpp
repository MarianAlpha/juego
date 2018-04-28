#include "menu1.h"
#include "ui_menu1.h"

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
