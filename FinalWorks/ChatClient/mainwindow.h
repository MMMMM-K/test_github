#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chatclient.h>
#include <QMutex>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool m_isAdmin = false;

private slots:
    void on_sent_clicked();
    void on_quit_clicked();
    void on_login_clicked();

    void connectedToserver();
    void messageReceived(const QString &sender,const QString &text);
    void jsonReceived(const QJsonObject &docObj);
    void userJoined(const QString &user);
    void userLeft(const QString &user);
    void userListReceived(const QStringList &list);

    void on_privateSayButton_clicked();
    void on_muteButton_clicked();
    void on_kickButton_clicked();
    void on_ummuteButton_clicked();

    void handleMuteChat();
    void handleUnmuteChat();
    void on_userList_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    ChatClient *m_chatClient;
    QMutex unmuteMutex;      //互斥锁
    bool unmuteMessageShown=false;
    bool userListUpdating;   //刷新用户列表
    bool inChatPage;         //判断是否在聊天界面
};
#endif // MAINWINDOW_H
