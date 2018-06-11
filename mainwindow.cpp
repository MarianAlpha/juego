#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "funciones.h"
#include <QLabel>
#include <QMovie>
#include <gameo.h>
#include "load.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player =new QMediaPlayer(this);                                                                   //Crea un tipo Media player
    player->setMedia(QUrl("qrc:/sonido/fondo.mp3"));                                                  //Reproducir la musica de fondo
    player->play();                                                                                   //Reproduce la musica

    QMovie *movie = new QMovie("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/Imagenes/perso.gif"); //Reproducir el gif
    ui->gif->setMovie(movie);
    movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;                                                          //Destructor
}

void MainWindow::on_Start_clicked()
{
    player->setMedia(QUrl("qrc:/sonido/boton.mp3"));                    //Sonido boton
    player->play();                                                     //Reproduce el sonido del boton

    menu1*MainWindow = new menu1;                                       //Crea la ventana menu1
    MainWindow->show();                                                 //Muestra la ventana
    close();                                                            //Cierra este widget
}
void MainWindow::on_quitgame_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/boton.mp3"));  //Sonido boton
    player->play();                                                                                             //Reproduce el sonido
    delay(3);                                                                                                   //Detiene el sistema
    close();                                                                                                    //Cierra el MainWindow
}

