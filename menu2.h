#ifndef MENU2_H
#define MENU2_H

#include <QWidget>
#include <QMediaPlayer>
#include <menu1.h>
#include <game.h>

namespace Ui {
class menu2;
}

class menu2 : public QWidget
{
    Q_OBJECT

public:
    explicit menu2(QWidget *parent = 0);
    ~menu2();

private slots:
    void on_return_2_clicked();

    void on_save_clicked();

private:
    Ui::menu2 *ui;
    QMediaPlayer *player;
};

#endif // MENU2_H
