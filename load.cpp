#include "load.h"
#include "ui_load.h"
#include <iostream>
#include <QMessageBox>
#include <fstream>

using namespace std;
extern gameO *gamme;
load::load(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::load)
{
    ui->setupUi(this);
}

load::~load()
{
    delete ui;                       //Destrucctor del juego
}

void load::on_back_clicked()
{
    menu1*menu2 = new menu1;        //Crea una ventana para el menu 1
    menu2->show();                  //Muestra el menu 1
    close();                        //Cierra este widget
}

void load::on_ok_clicked()
{
    b="holi";                                                                                 //Guarda algo en la variable donde se guarda el nick
    std::string var;                                                                          //Crea la variable var
    QString a= ui->nick->text()+".txt";                                                       //Guarda en a lo que se escribe en la linea de texto
    b = a.toLocal8Bit().constData();                                                          //Convierte el Qstring a String y lo guarda en la variable b
    ifstream load;                                                                            //Definimos en archivo en lectura
    load.open(b,ios::in);                                                                     // abrimos el archivo en modo lectura
    if(load.fail()){                                                                          //Si el archivo falla
        QMessageBox::information(this, tr("Error"), tr("Nombre de usuario Incorrecto"));      //Muestre un mensaje
    }
    else{                                                                                     //Si no falla
        QString a= ui->nick->text()+".txt";                                                   //Le concatene a b un .txt
        b = a.toLocal8Bit().constData();                                                      //De Qstring a string
        ofstream save;                                                                        //Define el archivo con escritura
        save.open("guardar.txt",ios::out);                                                    //Abre el archivo
        save<<b;                                                                              //Escribe a b en el archivo
        if(save.fail()) cout<<"Nop";                                                          //Si el archivo falla
        save.close();                                                                         //Cierra el archivo
        gamme = new gameO();                                                                  //Crea el juego
        gamme->show();                                                                        //Lo muestra
        close();                                                                              //Cierra el widget actual
    }

}
