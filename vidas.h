#ifndef VIDAS_H
#define VIDAS_H

#include <QObject>
#include <QSerialPort>
#include <QTimer>

class vidas : public QObject
{
    Q_OBJECT
public:
    explicit vidas(QObject *parent = nullptr);

    int vj1=5;
    QTimer *tiempo=new QTimer();

private slots:

    void vid();


private:
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 6790;
    static const quint16 arduino_uno_product_id = 29987;
    QString arduino_port_name;
    bool arduino_is_available;
};


#endif // VIDAS_H
