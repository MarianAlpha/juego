#ifndef VILLANO_H
#define VILLANO_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QGraphicsScene>

class villano: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    explicit villano(QGraphicsItem *parent = nullptr);
};

#endif // VILLANO_H
