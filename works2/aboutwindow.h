#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QWidget>

namespace Ui {
class Aboutwindow;
}

class Aboutwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Aboutwindow(QWidget *parent = nullptr);
    ~Aboutwindow();

private:
    Ui::Aboutwindow *ui;
};

#endif // ABOUTWINDOW_H
