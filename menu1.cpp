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
    player =new QMediaPlayer(this);                            //Crea la musica
    player->setMedia(QUrl("qrc:/sonido/menu1.mp3"));           //Define la musica de fondo
    player->play();                                            //Reproduce la musica
}

menu1::~menu1()
{
    delete ui;                                                //Destructor
}

void menu1::on_newgame_clicked()
{
    player->setMedia(QUrl("qrc:/sonido/boton.mp3"));         //Define la ruta del audio
    player->play();                                          //Reproduce el sonido
    menu = new menu2;                                        //Crea una vetana menu2
    menu->show();                                            //Muestra en menu 2
    close();                                                 //Cierra este widget
}

void menu1::on_loadgame_clicked()
{
    player->setMedia(QUrl("qrc:/sonido/boton.mp3"));        //Define la ruta del audio
    player->play();                                         //Reproduce el sonido
    load *loadd = new load();                               //Crea una ventana tipo load
    loadd->show();                                          //Muestra load
    close();                                                //Cierra este widget

}

void menu1::on_return_3_clicked()
{
    player->setMedia(QUrl("qrc:/sonido/boton.mp3"));       //Define la ruta del audio
    player->play();                                        //Reproduce el sonido
    MainWindow*menu1 = new MainWindow;                     //Crea un menu mainwindow
    menu1->show();                                         //Muestra el mainWindow
    close();                                               //Cierra este widget
}
