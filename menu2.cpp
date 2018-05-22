#include "menu2.h"
#include "ui_menu2.h"
#include "funciones.h"
#include <QMessageBox>
#include "QString"
#include <ctype.h>

menu2::menu2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu2)
{
    ui->setupUi(this);
    player =new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/menu2.mp3"));
    player->play();
}

menu2::~menu2()
{
    delete ui;
}

void menu2::on_return_2_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/boton.mp3"));
    player->play();
    delay(2);
    menu1*menu2 = new menu1;
    menu2->show();
    close();
}

void menu2::on_save_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/boton.mp3"));
    player->play();
    delay(2);

    QString respuesta1=ui->pregunta1->text();
    respuesta1=respuesta1.toLower();
    QString respuesta2=ui->pregunta2->text();
    respuesta2=respuesta2.toLower();
    QString respuesta3=ui->pregunta3->text();
    respuesta3=respuesta3.toLower();


    if(respuesta1=="link" && respuesta2=="kratos" && respuesta3=="pacman"){
        int a=1;
//        Gamee *game=new Gamee();
//        game->show();
//        close();
    }
    else {
        QMessageBox::information(this, tr("Error"), tr("Incorrecto").arg(respuesta1));
    }

}
