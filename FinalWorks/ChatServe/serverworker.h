#ifndef SERVERWORKER_H
#define SERVERWORKER_H

#include <QObject>
#include <QTcpSocket>
#include <QRunnable>

class ServerWorker : public QObject
{
    Q_OBJECT
public:
    explicit ServerWorker(QObject *parent = nullptr);
    virtual bool setSocketDescriptor(qintptr socketDescriptor);
    QString getuserName();
    void setUserName(QString user);

    bool isAdmin();
    void setIsAdmin(bool isAdmin);

signals:
    void logMessage(const QString &msg);
    void jsonReceived(ServerWorker *sender,const QJsonObject &docObj);
    void disconnectedFromClient();


private:
    QTcpSocket *m_serverSocket;
    QString userName;
    bool m_isAdmin=false;//判断是否为管理员
    bool m_isMuted = false; //判断是否全局禁言

public slots:
    void onReadyRead();
    void sendMessage(const QString &text, const QString &type = "message");
    void sendJson(const QJsonObject &json);

};

#endif // SERVERWORKER_H
