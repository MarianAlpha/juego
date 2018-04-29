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
}

menu2::~menu2()
{
    delete ui;
}

void menu2::on_return_2_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/boton.mp3"));
    player->play();
    delay(3);
    menu1*menu2 = new menu1;
    menu2->show();
    close();
}

void menu2::on_save_clicked()
{
    QString respuesta1=ui->pregunta1->text();
    respuesta1=respuesta1.toLower();
    QString respuesta2=ui->pregunta2->text();
    respuesta2=respuesta2.toLower();
    QString respuesta3=ui->pregunta3->text();
    respuesta3=respuesta3.toLower();
    if(respuesta1=="link" && respuesta2=="kratos" && respuesta3=="pacman"){
        QMessageBox::information(this, tr("holi"), tr("holi %1").arg(respuesta1));
    }
}
