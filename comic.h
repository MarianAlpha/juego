#ifndef COMIC_H
#define COMIC_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QMediaPlayer>

namespace Ui {
class comic;
}

class comic : public QWidget
{
    Q_OBJECT

public:
    explicit comic(QWidget *parent = 0);
    QGraphicsScene *scene;
    int nextt=0;
    QMediaPlayer *player;
    ~comic();

private slots:
    void on_pushButton_clicked();

private:
    Ui::comic *ui;
};

#endif // COMIC_H
