#ifndef MENU1_H
#define MENU1_H

#include <QWidget>
#include <QMediaPlayer>
#include <menu2.h>

namespace Ui {
class menu1;
}

class menu1 : public QWidget
{
    Q_OBJECT

public:
    explicit menu1(QWidget *parent = 0);
    ~menu1();

private slots:

    void on_newgame_clicked();

    void on_loadgame_clicked();

private:
    Ui::menu1 *ui;
    QMediaPlayer *player;
};

#endif // MENU1_H
