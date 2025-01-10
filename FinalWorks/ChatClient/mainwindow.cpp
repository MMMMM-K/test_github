#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QHostAddress"
#include "QJsonObject"
#include "QJsonValue"
#include <QMessageBox>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    inChatPage = false; // 初始化不在聊天界面

    m_chatClient = new ChatClient(this);
    connect(m_chatClient,&ChatClient::connected,this,&MainWindow::connectedToserver);
    connect(m_chatClient,&ChatClient::jsonReceived,this,&MainWindow::jsonReceived);
    connect(m_chatClient, &ChatClient::muteChat, this, &MainWindow::handleMuteChat);
    connect(m_chatClient, &ChatClient::unmuteChat, this, &MainWindow::handleUnmuteChat);
}
MainWindow::~MainWindow()
{
    delete ui;
}
//登录
void MainWindow::on_login_clicked()
{
    QString User = ui->nameEdit->text();
    QString Password = ui->passwordEdit->text();
    QString serverAddress = ui->serveEdit->text();
    if(User == "mym" && Password == "123456")
    {
        m_chatClient->connectToServer(QHostAddress(serverAddress),1967);
        m_isAdmin = false;
        m_chatClient->sendMessage(User, "login", "", false);
        return;
    }
    else if(User == "super" && Password == "654321")
    {
        m_chatClient->connectToServer(QHostAddress(serverAddress), 1967);
        m_isAdmin = true;
        m_chatClient->setAdminStatus(true);
        m_chatClient->sendMessage(User, "login", "", true);
        return;
    }
    else
    {
        QMessageBox::warning(this, "登录失败", "用户名或密码错误");
    }
}
//发送
void MainWindow::on_sent_clicked()
{
    if (m_chatClient->isMuted()) { // 检查全局禁言状态
        qDebug() << "Message not sent due to mute state.";
        QMessageBox::information(this, "禁言通知", "全体禁言中...");
        return;
    }
    if(!ui->messageEdit->text().isEmpty()) {
        bool isAdmin = m_isAdmin; // 判断是否为管理员
        m_chatClient->sendMessage(ui->messageEdit->text(), "message", "", isAdmin);

        QString sender = ui->messageEdit->text();
        QString text = ui->messageEdit->text();
        if (isAdmin) {
            ui->chatRecord->append(QString("%1[管理员]：%2").arg(sender).arg(text));
        } else {
            ui->chatRecord->append(QString("%1：%2").arg(sender).arg(text));
        }
    }
    ui->messageEdit->clear();
}
//退出
void MainWindow::on_quit_clicked()
{
    m_chatClient->disconnectFromHost();
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    inChatPage = false; // 设置为不在聊天界面
    for(auto aItem:ui->userList->findItems(ui->nameEdit->text(),Qt::MatchExactly))
    {
        qDebug("remove");
        ui->userList->removeItemWidget(aItem);
        delete aItem;
    }
}
void MainWindow::connectedToserver()
{
    ui->stackedWidget->setCurrentWidget(ui->chatPage);
    inChatPage = true;
    m_chatClient->sendMessage(ui->nameEdit->text(),"login");

    ui->privateTargetComboBox->setCurrentIndex(-1);// 设置默认不选择任何用户

}
void MainWindow::messageReceived(const QString &sender,const QString &text)
{
    ui->chatRecord->append(QString("%1:%2").arg(sender).arg(text));
}

void MainWindow::jsonReceived(const QJsonObject &docObj)
{
    const QJsonValue typeVal= docObj.value("type");
    if(typeVal.isNull()||!typeVal.isString())
    {
        return;
    }
    if(typeVal.toString().compare("message",Qt::CaseInsensitive)==0)
    {
        const QJsonValue textVal = docObj.value("text");
        const QJsonValue senderVal = docObj.value("sender");
        if(textVal.isNull()||!textVal.isString())
        {
            return;
        }
        if(senderVal.isNull()||!textVal.isString())
        {
            return;
        }
        QString sender = senderVal.toString();
        QString text = textVal.toString();
        // 如果发送者是管理员，修改消息格式
        if(sender!=ui->nameEdit->text())
        {
            if (docObj.contains("is_admin") && docObj.value("is_admin").toBool()&& typeVal.toString() == "message")
            {
                m_chatClient->setAdminStatus(true);
                ui->chatRecord->append(QString("%1[管理员]：%2").arg(sender).arg(text));
            }
            else
            {
                ui->chatRecord->append(QString("%1：%2").arg(sender).arg(text));
            }
        }
        ui->chatRecord->update();
        messageReceived(sender,text);
    }
    else if(typeVal.toString().compare("private",Qt::CaseInsensitive) == 0)
    {
        const QJsonValue senderVal = docObj.value("sender");
        const QJsonValue textVal = docObj.value("text");
        if(senderVal.isNull() ||!senderVal.isString())
        {
            return;
        }

        if(textVal.isNull() ||!textVal.isString())
        {
            return;
        }
        QString sender = senderVal.toString();
        QString text = textVal.toString();
        // 如果发送者是管理员，修改消息格式
        bool isAdmin = docObj.contains("is_admin") && docObj.value("is_admin").toBool();
        if(isAdmin)
        {
            ui->chatRecord->append(QString("%1[管理员]（私聊我）：%2").arg(sender).arg(text));
        }
        else
        {
            ui->chatRecord->append(QString("%1（私聊我）：%2").arg(sender).arg(text));
        }
        ui->chatRecord->update();
    }
    else if(typeVal.toString().compare("newuser",Qt::CaseInsensitive)==0)
    {
        const QJsonValue userNameVal = docObj.value("uername");
        bool isMuted = docObj["is_muted"].toBool();
        if(userNameVal.isNull()||!userNameVal.isString())
        {
            return;
        }
        userJoined(userNameVal.toString());
        if(isMuted)
        {
            m_chatClient->setMuted(true);
        }
    }
    else if(typeVal.toString().compare("userdisconnected",Qt::CaseInsensitive)==0)
    {
        const QJsonValue userNameVal = docObj.value("uername");
        if(userNameVal.isNull()||!userNameVal.isString())
        {
            return;
        }
        userLeft(userNameVal.toString());
    }
    else if(typeVal.toString().compare("userlist",Qt::CaseInsensitive)==0)
    {
        const QJsonValue userListVal = docObj.value("userlist");
        if(userListVal.isNull()||!userListVal.isArray())
        {
            return;
        }
        //qDebug()<< userListVal.toVariant().toStringList();
        userListReceived(userListVal.toVariant().toStringList());
    }
    else if(typeVal.toString().compare("userKicked", Qt::CaseInsensitive) == 0){
        const QJsonValue usernameVal = docObj.value("username");
        if(usernameVal.isNull() || !usernameVal.isString()){
            qDebug()<<"为空";
            return;
        }

        QString username = usernameVal.toString();
        // 从 privateTargetComboBox 中移除被踢出的用户
        int index = ui->privateTargetComboBox->findText(username);
        if (index != -1) {
            ui->privateTargetComboBox->removeItem(index);
        }

        // 如果被踢出的是当前用户，断开连接并返回登录界面
        if(username == ui->nameEdit->text() && inChatPage){
            QMessageBox::warning(this, "被踢出", "您已被管理员踢出聊天室。");
            m_chatClient->disconnectFromHost();
            ui->stackedWidget->setCurrentWidget(ui->loginPage);
            inChatPage = false;
            ui->chatRecord->append(QString("%1已被管理员踢出群聊").arg(username));
        }else {
            // 如果不是被踢出的用户，从用户列表中移除被踢出用户
            ui->chatRecord->append(QString("%1已被管理员踢出群聊").arg(username));
            userLeft(username);
        }
    }
    else if(typeVal.toString().compare("mute", Qt::CaseInsensitive) == 0){
        qDebug() << "MainWindow received mute message.";
        m_chatClient->setMuted(true);
        handleMuteChat();
    }
    else if(typeVal.toString().compare("unmute", Qt::CaseInsensitive) == 0){
        qDebug() << "MainWindow received unmute message.";
        m_chatClient->setMuted(false);
        handleUnmuteChat();
    }

}
void MainWindow::userJoined(const QString &user)
{
    ui->userList->addItem(user);
    ui->privateTargetComboBox->addItem(user);
}

void MainWindow::userLeft(const QString &user)
{
    for(auto aItem:ui->userList->findItems(user,Qt::MatchExactly))
    {
        qDebug("remove");
        ui->userList->removeItemWidget(aItem);
        delete aItem;
    }
    int index = ui->privateTargetComboBox->findText(user);
    if (index!= -1)
    {
        ui->privateTargetComboBox->removeItem(index);
    }
    // 用户列表界面刷新
    ui->userList->update();
}

void MainWindow::userListReceived(const QStringList &list)
{
    ui->userList->clear();
    ui->userList->addItems(list);
    userListUpdating = true;

    ui->privateTargetComboBox->clear();
    ui->privateTargetComboBox->addItems(list);
    ui->privateTargetComboBox->setCurrentIndex(-1);
    userListUpdating = false;
}
//私聊
void MainWindow::on_privateSayButton_clicked()
{
    if (m_chatClient->isMuted()) {
        qDebug() << "Private Message not sent due to mute state.";
        QMessageBox::information(this, "禁言通知", "当前处于禁言状态，无法发送消息");
        return;
    }

    QString text = ui->messageEdit->text();
    if(text.isEmpty())
        return;

    QString selectedTarget = ui->privateTargetComboBox->currentText();
    bool isAdmin = m_isAdmin && !selectedTarget.isEmpty(); // 根据当前用户的管理员状态传递参数
    if (selectedTarget.isEmpty()) {
        // 如果没有选择私聊对象，发送公开消息
        m_chatClient->sendMessage(text, "message", "", m_isAdmin);
    } else {
        m_chatClient->sendMessage(text, "private", selectedTarget,isAdmin);// 如果选择了私聊对象，发送私聊消息
        ui->chatRecord->append(QString("(我私聊%1) : %2").arg(selectedTarget).arg(text));// 将发送的私聊消息显示在自己的聊天界面
    }
}
//禁言
void MainWindow::on_muteButton_clicked()
{
    if (!m_isAdmin)
    {
        QMessageBox::warning(this, "权限不足", "您没有权限执行禁言操作");
        return;
    }
    qDebug() << "Mute button clicked";
    ui->muteButton->setEnabled(false); // 禁用按钮

    //m_chatClient->setMuted(true);
    m_chatClient->m_isMuted = true;
    qDebug() << "Set muted to true";
    m_chatClient->sendMessage("", "mute", "", true);
    qDebug() << "Sent mute message to server";

}
//解除禁言
void MainWindow::on_ummuteButton_clicked()
{
    if (!m_isAdmin) {
        QMessageBox::warning(this, "权限不足", "您没有权限执行此操作");
        return;
    }

    m_chatClient->m_isMuted = false;
    ui->muteButton->setEnabled(true);
    m_chatClient->sendMessage("", "unmute", "", true);
    qDebug() << "Sent unmute message to server";
    unmuteMessageShown = false;
}

void MainWindow::handleMuteChat()
{
    static bool isMuted = false;
    if (isMuted) return;
    isMuted = true;
    QMessageBox::information(this, "通知", "全体禁言已开启");
}

void MainWindow::handleUnmuteChat()
{
    QMutexLocker locker(&unmuteMutex);
    if (unmuteMessageShown) {
        qDebug() << "Unmute message already shown";
        return;
    }
    unmuteMessageShown = true;
    locker.unlock(); // 解锁
    qDebug() << "Handling unmute chat";
    QMessageBox::information(this, "通知", "全体禁言已解除");
}
//踢出
void MainWindow::on_kickButton_clicked()
{
    // 获取当前选中的用户
    QListWidgetItem *currentItem = ui->userList->currentItem();
    if (!currentItem) {
        QMessageBox::warning(this, "错误", "请选择一个用户进行踢出操作！");
        return;
    }

    if (!m_isAdmin) {
        QMessageBox::warning(this, "权限不足", "您没有权限执行踢出操作");
        return;
    }

    QString selectedUser = currentItem->text();
    if (!selectedUser.isEmpty()) {
        m_chatClient->sendMessage("", "kick", selectedUser, m_isAdmin);// 发送踢出指令给服务器

        // 从本地用户列表中移除被踢用户
        for (auto aItem : ui->userList->findItems(selectedUser, Qt::MatchExactly)) {
            ui->userList->removeItemWidget(aItem);
            delete aItem;
        }

        // 从privateTargetComboBox中移除被踢用户
        int index = ui->privateTargetComboBox->findText(selectedUser);
        if (index!= -1) {
            ui->privateTargetComboBox->removeItem(index);
        }
    }
}
//双击选择用户
void MainWindow::on_userList_itemDoubleClicked(QListWidgetItem *item)
{
    QString selectedUser = item->text();
    ui->privateTargetComboBox->setCurrentText(selectedUser);
}

