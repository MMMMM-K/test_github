#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zero,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->one,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->two,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->three,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->four,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->five,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->six,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->seven,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->eight,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->nine,SIGNAL(clicked()),this,SLOT(btnNumClicked()));


    connect(ui->add,SIGNAL(clicked()),this,SLOT(btnDoubleOperator()));
    connect(ui->minus,SIGNAL(clicked()),this,SLOT(btnDoubleOperator()));
    connect(ui->multiply,SIGNAL(clicked()),this,SLOT(btnDoubleOperator()));
    connect(ui->divide,SIGNAL(clicked()),this,SLOT(btnDoubleOperator()));

    connect(ui->Button,SIGNAL(clicked()),this,SLOT(btnSingleOperator()));
    connect(ui->Reciprocal,SIGNAL(clicked()),this,SLOT(btnSingleOperator()));
    connect(ui->square,SIGNAL(clicked()),this,SLOT(btnSingleOperator()));
    connect(ui->root,SIGNAL(clicked()),this,SLOT(btnSingleOperator()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::btnNumClicked()
{
    QString digit = qobject_cast<QPushButton *>(sender())->text();
    if(digit=="0"&&operand=="0")
    {
        digit="";
    }
    if(operand=="0"&&digit!="0")
    {
        operand="";
    }
    operand += digit;
    ui->Display->setText(operand);
    ui->statusbar->showMessage("Button clicked");
}

void MainWindow::on_point_clicked()
{

    if(!operand.contains(".")&&operand!="")
    {
        operand += qobject_cast<QPushButton *>(sender())->text();
    }
    ui->Display->setText(operand);
}

void MainWindow::on_Delete_clicked()
{
    operand = operand.left(operand.length()-1);
    ui->Display->setText(operand);
}

void MainWindow::on_clear_clicked()
{
    operand.clear();

    while(operands.size()!=0)
    {
        operands.pop_front();
    }
    while(code.size()!=0)
    {
        code.pop_front();
    }
    ui->statusbar->showMessage(QString("C.operands = %1,code = %2").arg(operands.size()).arg(code.size()));
    ui->Display->setText(operand);
}

void MainWindow::btnDoubleOperator()
{

    QString opcode= qobject_cast<QPushButton *>(sender())->text();
    if(operand!="")
    {
        operands.push_back(operand);
        operand="";
        code.push_back(opcode);

        QString result = calculation();
        ui->Display->setText(result);
    }
}

QString MainWindow::calculation(bool *ok)           //取操作数
{
    double result = 0;
    if(operands.size()==2 && code.size()>0)
    {
        double operand1=operands.front().toDouble();
        operands.pop_front();
        double operand2=operands.front().toDouble();
        operands.pop_front();

        QString op = code.front();
        code.pop_front();

        if(op=="+")
        {
            result = operand1+operand2;
        }
        else if(op=="-")
        {
            result = operand1-operand2;
        }
        else if(op=="×")
        {
            result = operand1*operand2;
        }
        else if(op=="÷")
        {
            if(operand1!=0&&operand2!=0)
            {
                result = operand1/operand2;
            }
            ui->statusbar->showMessage("!!!");
        }
        operands.push_back(QString::number(result));
        ui->statusbar->showMessage(QString("operands = %1,code = %2").arg(operands.size()).arg(code.size()));
    }
    else
    {
        ui->statusbar->showMessage(QString("!operabds = %1,code = %2").arg(operands.size()).arg(code.size()));
    }
    return QString::number(result);
}

void MainWindow::btnSingleOperator()
{
    if(operand!="")
    {
        double result = operand.toDouble();
        operand = "";

        QString op= qobject_cast<QPushButton *>(sender())->text();
        if(op=="%")
        {
            result/=100.0;
        }
        else if(op=="1/x")
        {
            result = 1/result;
        }
        else if(op=="x²")
        {
            result = result*result;
        }
        else if(op=="√x")
        {
            result = sqrt(result);
        }
        ui->Display->setText(QString::number(result));
    }
}

void MainWindow::on_equal_clicked()
{
    if(operand!="")
    {
        operands.push_back(operand);
        operand="";
    }
    QString result = calculation();
    ui->Display->setText(result);
    while(operands.size()!=0)
    {
        operands.pop_front();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_0)
    {
        ui->zero->click();
    }
    if(event->key()==Qt::Key_1)
    {
        ui->one->click();
    }
    if(event->key()==Qt::Key_2)
    {
        ui->two->click();
    }
    if(event->key()==Qt::Key_3)
    {
        ui->three->click();
    }
    if(event->key()==Qt::Key_4)
    {
        ui->four->click();
    }
    if(event->key()==Qt::Key_5)
    {
        ui->five->click();
    }
    if(event->key()==Qt::Key_6)
    {
        ui->six->click();
    }
    if(event->key()==Qt::Key_8)
    {
        ui->seven->click();
    }
    if(event->key()==Qt::Key_9)
    {
        ui->seven->click();
    }
    if(event->key()==Qt::Key_Backspace)
    {
        ui->Delete->click();
    }
    if(event->key()==Qt::Key_Percent)
    {
        ui->Button->click();
    }
    if(event->key()==Qt::Key_Plus)
    {
        ui->add->click();
    }
    if(event->key()==Qt::Key_Minus)
    {
        ui->minus->click();
    }
    if(event->key()==Qt::Key_Asterisk)
    {
        ui->multiply->click();
    }
    if(event->key()==Qt::Key_Slash)
    {
        ui->divide->click();
    }
    if(event->key()==Qt::Key_Period)
    {
        ui->point->click();
    }
    if(event->key()==Qt::Key_Enter)
    {
        ui->equal->click();
    }
}

