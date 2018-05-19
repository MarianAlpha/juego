#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QDebug>
#include <menu1.h>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Start_clicked();

    void on_quitgame_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
};

#endif // MAINWINDOW_H
