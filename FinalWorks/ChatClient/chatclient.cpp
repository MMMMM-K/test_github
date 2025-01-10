#include "chatclient.h"
#include "QDataStream"
#include "QJsonObject"
#include "QJsonDocument"
#include <QMessageBox>
#include <QMutexLocker>

ChatClient::ChatClient(QObject *parent)
    : QObject{parent}
{
    m_clientSocket = new QTcpSocket(this);
    connect(m_clientSocket,&QTcpSocket::connected,this,&ChatClient::connected);
    connect(m_clientSocket,&QTcpSocket::readyRead,this,&ChatClient::onReadyRead);
}
//是否登录
bool ChatClient::isAdmin() const
{
    return m_isAdmin;
}
//设置登录状态
void ChatClient::setAdminStatus(bool isAdmin)
{
    m_isAdmin = isAdmin;
}
//是否禁言
bool ChatClient::isMuted()
{
    QMutexLocker locker(&m_muteMutex);
    return m_isMuted;
}
//设置禁言
void ChatClient::setMuted(bool muted)
{
    if (m_isMuted != muted) {
        QMutexLocker locker(&m_muteMutex);
        m_isMuted = muted;
        qDebug() << "Mute state set to:" << muted;
        if (muted) {
            emit muteChat();
        } else {
            emit unmuteChat();
        }
    }
}
void ChatClient::onReadyRead()
{
    QByteArray jsonData;
    QDataStream socketStream(m_clientSocket);
    socketStream.setVersion(QDataStream::Qt_6_7);
    for(;;)
    {
        socketStream.startTransaction();
        socketStream >> jsonData;
        if(socketStream.commitTransaction())//提交成功
        {
            //emit messageReceived(QString::fromUtf8(jsonData));
            QJsonParseError parseError;
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData,&parseError);
            if(parseError.error == QJsonParseError::NoError)
            {
                if(jsonDoc.isObject())
                {
                    //emit logMessage(QJsonDocument(jsonDoc).toJson(QJsonDocument::Compact));
                    emit jsonReceived(jsonDoc.object());

                    QJsonObject jsonDocObj = jsonDoc.object();
                    if(jsonDocObj["type"] == "mute")
                    {
                        // m_isMuted = true;
                        bool muted = jsonDocObj.contains("is_muted") && jsonDocObj["is_muted"].toBool();
                        setMuted(muted);
                        emit muteChat();
                        qDebug() << "Client received mute message.";
                    }
                    else if(jsonDocObj["type"] == "unmute")
                    {
                        // m_isMuted = false;
                        bool muted = jsonDocObj.contains("is_muted") && jsonDocObj["is_muted"].toBool();
                        setMuted(muted);
                        emit unmuteChat();
                        qDebug() << "Client received unmute message.";
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
}
void ChatClient::sendMessage(const QString &text, const QString &type, const QString &target, bool isAdmin)
{
    qDebug() << "sendMessage called with type:" << type;
    if(m_clientSocket->state() != QAbstractSocket::ConnectedState){//先判断当前m_serverSocket的状态是否为已连接状态
        qDebug() << "Socket is not connected, cannot send message.";
        return;
    }

    if(!text.isEmpty() || type == "disconnect" || type == "kick" || type == "mute" || type == "unmute"){
        QDataStream serverStream(m_clientSocket);
        serverStream.setVersion(QDataStream::Qt_6_7);

        QJsonObject message;
        message["type"]=type;
        message["text"]=text;
        if (type == "private" || type == "kick" ) {
            message["target"] = target;  // 如果是私聊消息，设置接收方用户名
        }

        // 如果是管理员且发送类型为message，添加管理员权限信息
        if (isAdmin && (type == "message" || type == "private" || type == "kick" || type == "mute" || type == "unmute")) {
            message["is_admin"] = true;
        }

        serverStream <<QJsonDocument(message).toJson();//<<操作符将各种数据类型写入QDataStream
    }
}
void ChatClient::connectToServer(const QHostAddress &address, quint16 port)
{
    m_clientSocket->connectToHost(address,port);
}

void ChatClient::disconnectFromHost()
{
    QJsonObject disconnectMsg;
    disconnectMsg["type"] = "disconnect";
    sendMessage("", "disconnect", "", false);
    m_clientSocket->disconnectFromHost();
}
