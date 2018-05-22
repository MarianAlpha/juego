#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "funciones.h"
#include <QLabel>
#include <QMovie>
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //setStyleSheet("background-image: url(C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/Imagenes/citrus.png);");
    ui->setupUi(this);
    player =new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/fondo.mp3")); //Reproducir la musica de fondo
    player->play();

    QMovie *movie = new QMovie("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/Imagenes/perso.gif"); //Reproducir el gif
    ui->gif->setMovie(movie);
    movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Start_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/boton.mp3")); //Sonido boton
    player->play();
    delay(2);

    /*menu1*MainWindow = new menu1; //pasar de mainwindow a menu1
    MainWindow->show();
    close();*/
    game *gamme =new game();
    gamme->show();
    close();

}
void MainWindow::on_quitgame_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/boton.mp3")); //Sonido boton
    player->play();
    delay(3);
    close();
}

