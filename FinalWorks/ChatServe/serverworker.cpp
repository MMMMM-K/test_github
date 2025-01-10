#include "serverworker.h"
#include "chatserver.h"
#include "QDataStream"
#include "QJsonObject"
#include "QJsonDocument"

ServerWorker::ServerWorker(QObject *parent)
    : QObject{parent}
{
    m_serverSocket = new QTcpSocket(this);
    connect(m_serverSocket,&QTcpSocket::readyRead,this,&ServerWorker::onReadyRead);
    connect(m_serverSocket,&QTcpSocket::disconnected,this,&ServerWorker::disconnectedFromClient);
}
bool ServerWorker::setSocketDescriptor(qintptr socketDescriptor)
{
    return m_serverSocket->setSocketDescriptor(socketDescriptor);
}

QString ServerWorker::getuserName()
{
    return userName;
}
void ServerWorker::setUserName(QString user)
{
    userName = user;
}

bool ServerWorker::isAdmin()
{
    return m_isAdmin;
}

void ServerWorker::setIsAdmin(bool isAdmin)
{
    m_isAdmin = isAdmin;
}
void ServerWorker::onReadyRead()
{
    QByteArray jsonData;
    QDataStream socketStream(m_serverSocket);
    socketStream.setVersion(QDataStream::Qt_6_7);

    for(;;)
    {
        socketStream.startTransaction();
        socketStream >> jsonData;
        if(socketStream.commitTransaction())
        {
            //emit logMessage(QString::fromUtf8(jsonData));
            //sendMessage("I recieved message");

            QJsonParseError parseError;
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData,&parseError);
            if(parseError.error == QJsonParseError::NoError)
            {
                if(jsonDoc.isObject())
                {
                    emit logMessage(QJsonDocument(jsonDoc).toJson(QJsonDocument::Compact));
                    emit jsonReceived(this, jsonDoc.object());
                }
            }
        }
        else
        {
            break;
        }
    }
}
void ServerWorker::sendMessage(const QString &text, const QString &type)
{
    if(m_serverSocket->state()!=QAbstractSocket::ConnectedState)
        return;
    if(!text.isEmpty())
    {
        QDataStream serverStream(m_serverSocket);
        serverStream.setVersion(QDataStream::Qt_6_7);
        QJsonObject message;
        message["type"] = type;
        message["text"] = text;
        serverStream<<QJsonDocument(message).toJson();
    }
}

void ServerWorker::sendJson(const QJsonObject &json)
{
    const QByteArray jsonData = QJsonDocument(json).toJson(QJsonDocument::Compact);
    emit logMessage(QLatin1StringView("Sending to") + getuserName() + QLatin1String("-")+QString::fromUtf8(jsonData));
    QDataStream socketStream(m_serverSocket);
    socketStream.setVersion(QDataStream::Qt_6_7);
    socketStream << jsonData;
}
