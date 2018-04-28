#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "funciones.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player =new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/fondo.mp3"));
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Start_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Documents/Tareas/InfoII/JuegoII/sonido/boton.mp3"));
    player->play();
    delay(3);
    menu1*MainWindow = new menu1;
    MainWindow->show();
    close();

}
