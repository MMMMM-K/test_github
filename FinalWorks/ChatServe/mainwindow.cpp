#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_chatServer = new ChatServer(this);

    connect(m_chatServer,&ChatServer::logMessage,this,&MainWindow::logMessage);
}
MainWindow::~MainWindow()
{
    if(m_chatServer->isListening())
    {
        m_chatServer->stopServer();
    }
    delete ui;
}
void MainWindow::on_serveAction_clicked()
{
    if(m_chatServer->isListening())
    {
        m_chatServer->stopServer();
        ui->serveAction->setText("启动服务器");
        logMessage("服务器已停止");
    }
    else
    {
        if(!m_chatServer->listen(QHostAddress::Any,1967))
        {
            QMessageBox::critical(this,"wrong!","无法启动服务器");
            return;
        }
        logMessage("服务器已启动");
        ui->serveAction->setText("停止服务器");
    }
}
void MainWindow::logMessage(const QString &msg)
{
    ui->textShow->appendPlainText(msg);
}

