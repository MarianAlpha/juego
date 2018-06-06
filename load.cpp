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
    delete ui;
}

void load::on_back_clicked()
{
    menu1*menu2 = new menu1;
    menu2->show();
    close();
}

void load::on_ok_clicked()
{
    b="holi";
    std::string var;
    QString a= ui->nick->text()+".txt";
    b = a.toLocal8Bit().constData();
    ifstream load;
    load.open(b,ios::in); // abrimos el archivo en modo lectura
    if(load.fail()){
        QMessageBox::information(this, tr("Error"), tr("Nombre de usuario Incorrecto"));
    }
    else{
        QString a= ui->nick->text()+".txt";
        b = a.toLocal8Bit().constData();
        ofstream save;
        save.open("guardar.txt",ios::out);
        save<<b;
        if(save.fail()) cout<<"Nop";
        save.close();
        gamme = new gameO();
        gamme->show();
        close();
    }

}
