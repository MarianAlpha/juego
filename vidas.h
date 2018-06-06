#ifndef VIDAS_H
#define VIDAS_H

#include <QObject>
#include <QSerialPort>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QMediaPlayer>

class vidas : public QObject
{
    Q_OBJECT
public:
    explicit vidas(QObject *parent = nullptr);

    int vj1=9;
    int vj2=9;
    QTimer *tiempo=new QTimer();
    QMediaPlayer *play =new QMediaPlayer();
    QGraphicsTextItem *over;
    void decrece1();
    void decrece2();
    void GameOver();

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
