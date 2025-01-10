#include "chatserver.h"
#include "serverworker.h"
#include "QJsonObject"
#include "QJsonValue"
#include "QJsonArray"

ChatServer::ChatServer(QObject *parent):
    QTcpServer(parent)
{
    m_pool = new QThreadPool(this);
    m_pool->setMaxThreadCount(10); // 设置最大线程数
}

ChatServer::~ChatServer()
{
    m_pool->waitForDone();
    delete m_pool;
}

void ChatServer::run()
{

}
void ChatServer::incomingConnection(qintptr soketDescriptor)
{
    ServerWorker *worker = new ServerWorker(this);
    if(!worker->setSocketDescriptor(soketDescriptor))
    {
        worker->deleteLater();
        return;
    }
    connect(worker,&ServerWorker::logMessage,this,&ChatServer::logMessage);
    connect(worker,&ServerWorker::jsonReceived,this,&ChatServer::jsonReceived);
    connect(worker,&ServerWorker::disconnectedFromClient,this,std::bind(&ChatServer::userDisconnected,this,worker));

    // 创建一个新的线程并移动 worker 到该线程
    QThread *thread = new QThread;
    worker->moveToThread(thread);
    thread->start();

    m_clients.append(worker);
    emit logMessage("新用户已连接");
}

void ChatServer::broadcast(const QJsonObject &message, ServerWorker *exclude)
{
    m_clientListMutex.lock();
    for(ServerWorker *worker : m_clients)
    {
        if(worker!=exclude)
        {
            qDebug() << "Broadcasting message to" << worker->getuserName();
            worker->sendJson(message);
        }
    }
    m_clientListMutex.unlock();
}
void ChatServer::stopServer()
{
    close();
    m_pool->clear();  //清空线程池中尚未执行的任务或线程池状态
}
void ChatServer::jsonReceived(ServerWorker *sender, const QJsonObject &docObj)
{
    const QJsonValue typeVal= docObj.value("type");
    if(typeVal.isNull()||!typeVal.isString())
    {
        return;
    }
    if(typeVal.toString().compare("message",Qt::CaseInsensitive)==0)
    {
        const QJsonValue textVal = docObj.value("text");
        if(textVal.isNull()||!textVal.isString())
        {
            return;
        }
        const QString text = textVal.toString().trimmed();
        if(text.isEmpty())
        {
            return;
        }
        QJsonObject message;
        message["type"] = "message";
        message["text"] = text;
        message["sender"] = sender->getuserName();

        bool isAdmin = docObj.contains("is_admin") && docObj.value("is_admin").toBool();
        // 如果发送者是管理员，修改消息格式
        if (isAdmin) {
            qDebug() << "Server sender admin status: " << sender->isAdmin();
            message["sender"] = sender->getuserName() + "[管理员]";
        }
        else {
            message["sender"] = sender->getuserName();
        }

        broadcast(message,sender);
    }
    else if(typeVal.toString().compare("login",Qt::CaseInsensitive)==0)
    {
        const QJsonValue userNameVal = docObj.value("text");
        if(userNameVal.isNull()||!userNameVal.isString())
        {
            return;
        }
        sender->setUserName(userNameVal.toString());
        // 获取登录消息中的管理员权限信息并设置
        const QJsonValue isAdminVal = docObj.value("is_admin");
        if (isAdminVal.isBool())
        {
            sender->setIsAdmin(isAdminVal.toBool());
        }
        else
        {
            sender->setIsAdmin(false); //默认设置为非管理员
        }

        QJsonObject connectedMessage;
        connectedMessage["type"] = "newuser";
        connectedMessage["userName"] = userNameVal.toString();
        connectedMessage["is_muted"] = m_isMuted; // 添加当前禁言状态
        broadcast(connectedMessage,sender);

        //发userlist给新登录的用户
        QJsonObject userListMessage;
        userListMessage["type"]="userlist";
        QJsonArray userlist;
        for(ServerWorker *worker:m_clients)
        {
            if(worker == sender)
                userlist.append(worker->getuserName()+"*");
            else
                userlist.append(worker->getuserName());
        }
        userListMessage["userlist"] = userlist;
        sender->sendJson(userListMessage);
    }
    else if (typeVal.toString().compare("private", Qt::CaseInsensitive) == 0)
    {
        const QJsonValue targetVal = docObj.value("target");
        if (targetVal.isNull() ||!targetVal.isString())
            return;

        const QString target = targetVal.toString();
        const QJsonValue textVal = docObj.value("text");
        if (textVal.isNull() ||!textVal.isString())
            return;
        const QString text = textVal.toString().trimmed();
        if (text.isEmpty())
            return;

        QJsonObject privateMessage;
        privateMessage["type"] = "private";
        privateMessage["text"] = text;
        // 如果发送者是管理员，修改消息格式
        bool isAdmin = docObj.contains("is_admin") && docObj.value("is_admin").toBool();
        if (isAdmin)
        {
            privateMessage["sender"] = sender->getuserName() + "[管理员]";
        }
        else
        {
            privateMessage["sender"] = sender->getuserName();
        }
        for (ServerWorker *worker : m_clients)
        {
            if (worker->getuserName() == target)
            {
                worker->sendJson(privateMessage);
                break;
            }
        }
    }
    else if(typeVal.toString().compare("kick", Qt::CaseInsensitive) == 0){
        // 检查发送者是否为管理员
        const QJsonValue isAdminVal = docObj.value("is_admin");
        if (isAdminVal.isBool()) {
            const QJsonValue targetVal = docObj.value("target");
            if (targetVal.isNull() ||!targetVal.isString())
                return;

            const QString targetUsername = targetVal.toString();
            // 广播用户被踢出的消息给其他客户端（排除发送者）
            QJsonObject kickedMessage;
            kickedMessage["type"] = "userKicked";
            kickedMessage["username"] = targetUsername;
            broadcast(kickedMessage, sender);
            // 发送被踢出消息给目标客户端，并断开连接
            QJsonObject kickNotice;
            kickNotice["type"] = "userKicked";
            kickNotice["username"] = targetUsername;
            ServerWorker *targetWorker = nullptr;
            for (ServerWorker *worker : m_clients)
            {
                if (worker->getuserName() == targetUsername)
                {
                    targetWorker = worker;
                    break;
                }
            }
            if (targetWorker)
            {
                targetWorker->sendJson(kickNotice);
                m_clients.removeAll(targetWorker);
            }
        }
        return;
    }
    else if (typeVal.toString().compare("disconnect", Qt::CaseInsensitive) == 0)
    {
        userDisconnected(sender);
        return;
    }
    else if (typeVal.toString().compare("mute", Qt::CaseInsensitive) == 0)
    {
        bool isAdmin = docObj.contains("is_admin") && docObj.value("is_admin").toBool();
        if(!isAdmin)
        {
            qDebug()<<"不是管理员";
            return;
        }

        QString senderName = docObj.value("sender").toString();
        qDebug() << "Server received mute message from" << senderName;
        m_isMuted = true;
        qDebug() << "Server: Mute activated by admin.";
        emit logMessage("管理员开启禁言");

        QJsonObject muteMessage;
        muteMessage["type"]="mute";
        muteMessage["is_muted"] = true;
        broadcast(muteMessage,nullptr);
    }
    else if(typeVal.toString().compare("unmute", Qt::CaseInsensitive) == 0)
    {
        bool isAdmin = docObj.contains("is_admin") && docObj.value("is_admin").toBool();
        if(!isAdmin)
        {
            qDebug()<<"不是管理员";
            return;
        }
        m_isMuted = false; // 更新全局禁言状态
        qDebug() << "Server: Unmute activated by admin.";
        emit logMessage("管理员解除禁言");
        QJsonObject unmuteMessage;
        unmuteMessage["type"]="unmute";
        unmuteMessage["is_muted"] = false;
        broadcast(unmuteMessage, nullptr);
    }
}
void ChatServer::userDisconnected(ServerWorker *sender)
{
    m_clientListMutex.lock();
    m_clients.removeAll(sender);
    m_clientListMutex.unlock();
    const QString userName = sender->getuserName();
    if(!userName.isEmpty())
    {
        QJsonObject disconnectedMessage;
        disconnectedMessage["type"] = "userdisconnected";
        disconnectedMessage["username"] = userName;
        broadcast(disconnectedMessage,nullptr);
        emit logMessage(userName + "disconnected");
    }
    sender->deleteLater();
}
