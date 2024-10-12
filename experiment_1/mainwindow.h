#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QKeyEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString operand;
    QStack<QString> operands;
    QStack<QString> code;
    QStack<QString> answer;

    QString calculation(bool *ok=NULL);
private slots:

    void btnNumClicked();              //数字按键

    void on_point_clicked();           //小数点按键

    void on_Delete_clicked();          //删除键

    void on_clear_clicked();           //清除键

    void btnDoubleOperator();          //双操作符功能键

    void btnSingleOperator();          //单操作符功能键

    void on_equal_clicked();           //等于号

    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
