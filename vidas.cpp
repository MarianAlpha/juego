#include "vidas.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

vidas::vidas(QObject *parent) : QObject(parent)
{
    arduino_is_available = false;
    arduino_port_name = "COM4";
    arduino = new QSerialPort;
    connect(tiempo,SIGNAL(timeout()),this,SLOT(vid()));
    tiempo->start(2000);



    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }

    if(arduino_is_available){
        // open and configure the serialport
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::WriteOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }
}

void vidas::vid()
{
//   vj1--;
    if(vj1==5){
        if(arduino->isWritable()){
            arduino->write("5");}}

    if(vj1==4){
        if(arduino->isWritable()){
            arduino->write("4");}}

    if(vj1==3){
        if(arduino->isWritable()){
            arduino->write("3");}}

    if(vj1==2){
        if(arduino->isWritable()){
            arduino->write("2");}}

    if(vj1==1){
        if(arduino->isWritable()){
            arduino->write("1");}}

    if(vj1==0){
        if(arduino->isWritable()){
            arduino->write("0");}}

    if(vj1<0){
        if(arduino->isWritable()){
            arduino->write("9");}
    }
}
