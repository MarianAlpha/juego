#include "load.h"
#include "ui_load.h"
#include "menu1.h"
#include <iostream>
#include <Vector>
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
    menu1 *back = new menu1();
    back->show();
    close();
}

void load::on_ok_clicked()
{
    QString a= ui->nick->text()+".txt";
    b = a.toLocal8Bit().constData();
    string var;
    int ent;
    vector<int> lis;
    ifstream load;
    load.open(b,ios::in); // abrimos el archivo en modo lectura
    if(load.fail()){
        cout<<"No se puedo abrir el archivo";
    }
    else{
        while(!load.eof()){
            getline(load, var);
            ent = atoi(var.c_str());
        }
    }
}
