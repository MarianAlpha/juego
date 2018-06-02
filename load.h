#ifndef LOAD_H
#define LOAD_H

#include <QWidget>
#include <iostream>

namespace Ui {
class load;
}

class load : public QWidget
{
    Q_OBJECT

public:
    explicit load(QWidget *parent = 0);
    ~load();
    std::string b;

private slots:
    void on_back_clicked();

    void on_ok_clicked();

private:
    Ui::load *ui;
};

#endif // LOAD_H
