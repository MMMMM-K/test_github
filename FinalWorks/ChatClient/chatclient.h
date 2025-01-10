#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
#include <QTcpsocket>
#include <QMessageBox>
#include <QMutex>
#include <QMutexLocker>

class ChatClient : public QObject
{
    Q_OBJECT
public:
    explicit ChatClient(QObject *parent = nullptr);
    bool m_isAdmin = false;             //登录状态
    bool isAdmin()const;
    void setAdminStatus(bool isAdmin);
    bool m_isMuted = false;             //禁言状态
    bool isMuted();
    void setMuted(bool muted);
signals:
    void connected();
    void messageReceived(const QString &text);
    void jsonReceived(const QJsonObject &docObj);
    void muteChat();
    void unmuteChat();

private:
    QTcpSocket *m_clientSocket;
    QMutex m_muteMutex; // 互斥锁保护全局禁言状态

public slots:
    void onReadyRead();
    void sendMessage(const QString &text, const QString &type="message", const QString &target="", bool isAdmin="");//发送消息
    void connectToServer(const QHostAddress &address,quint16 port);
    void disconnectFromHost();

};

#endif // CHATCLIENT_H
