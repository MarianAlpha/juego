#include "menu2.h"
#include "ui_menu2.h"
#include "funciones.h"
#include <QMessageBox>
#include "QString"
#include "comic.h"
#include <ctype.h>
#include "stdlib.h"
#include <iostream>
#include <fstream>

using namespace std;

menu2::menu2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu2)
{
    ui->setupUi(this);
    player =new QMediaPlayer(this);                             //Define el media player
    player->setMedia(QUrl("qrc:/sonido/menu2.mp3"));            //Define la ruta del audio
    player->play();                                             //Reproduce el audio
}

menu2::~menu2()
{
    delete ui;                                                  //Destrucctor del juego
}

void menu2::on_return_2_clicked()
{
    player->setMedia(QUrl("qrc:/sonido/boton.mp3"));           //Define la ruta del audio
    player->play();                                            //Reproduce la musica
    delay(2);
    menu1*menu2 = new menu1;                                   //Crea una ventana menu 1
    menu2->show();                                             //Muestra el menu 1
    close();                                                   //Cierra este widget
}

void menu2::on_save_clicked()
{
    player->setMedia(QUrl("qrc:/sonido/boton.mp3"));          //Define la ruta del audio
    player->play();                                           //Reproduce el sonido
    delay(2);                                                 //Para el tiempo

    QString respuesta1=ui->pregunta1->text();                 //Guarda la primera respuesta de la linea de texto
    respuesta1=respuesta1.toLower();                          //La convierte en minuscula
    QString respuesta2=ui->pregunta2->text();                 //Guarda la segunda respuesta de la linea de texto
    respuesta2=respuesta2.toLower();                          //La convierte a minuscula
    QString respuesta3=ui->pregunta3->text();                 //Guarda la tercera respuesta de la linea de texto
    respuesta3=respuesta3.toLower();                          //La convierte a minuscula


    if(respuesta1=="link" && respuesta2=="kratos" && respuesta3=="pacman"){   //Si las respuestas son correctas
        QString a= ui->nick->text()+".txt";                                   //Concatena el .txt al nick
        b = a.toLocal8Bit().constData();                                      //Lo pasa de Qstring a string
        ofstream save;                                                        //Crea el archivo como escritura
        save.open(b,ios::out);                                                //Abre el archivo
        if(save.fail()) cout<<"Nop";                                          //Si el archivo falla

        comic *gamme =new comic();                                            //Crea la ventana del comic
        gamme->show();                                                        //Muestra el comic
        close();                                                              //Cierra la ventana
    }
    else {                                                                    //Si las respuestas no son correctas
        QMessageBox::information(this, tr("Error"), tr("Incorrecto").arg(respuesta1));   //Muestra un mensaje
    }
}
