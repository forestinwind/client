#include <qdebug.h>
#include <fstream>
#include <qfile.h>
#include <qiodevice.h>

#include "client.h"
#include "..\shared\shared.h"


client::client() 
{
    userId = -1;
    connect(&thisSock, &QTcpSocket::readyRead, this, &client::readSockSlot);
    curId = 0;
}
client::~client()
{
    thisSock.disconnectFromHost();
    sendMessageSlot("LOGOUT");
}
bool client::begin()//connect未建立，我不能将向上传递的信号放在构造函数
{
    QFile serverFILE("serverIP.txt");
    serverFILE.open(QIODevice::ReadOnly);
    QTextStream in(&serverFILE);
    if(serverFILE.isOpen())
    {
        in >> serverIP;
        in >> servetPort;
        qDebug() << "readfile";
    }
    thisSock.connectToHost(QHostAddress(serverIP), servetPort);
    //thisSock.write("michael");
    if (thisSock.waitForConnected(5000))
    {
        qDebug()<<serverIP<<servetPort;
        emit writeBrowserSignal("Connected");
        return true;
    }
    else {
        emit writeBrowserSignal("failed");
        return false;
    }
}
void client::readSockSlot()
{
    QByteArray buffer;
    buffer = thisSock.readAll();
    QString str = tr(buffer);
    if (str!="")
    {
        qDebug() << str;
        emit writeBrowserSignal(str);
        QString cur;
        while ((cur = divide(str, END_CMD)) != "")
        {
            qDebug("??");
            emit writeBrowserSignal(cur);//这里有error，原因不明，疑似是因为_CMD分割符
            qDebug("???");
            int cmdid = divide(cur, DIV_CMD).toInt(); //命令id，需要等待回应

            QString cmd = divide(cur, DIV_CMD);
            if(cmd=="LOGINSUCCEES")
            {
                loginSucceed(cur);
                emit closeLoginWidgetSignal();
                emit showChatWidgetSignal();
            }
            if (cmd == "CHATRECORD")
            {
                emit chatRecordSignal(cur);
            }
            if (cmd == "CHATADD")
            {
                writeBrowserSignal(cur);
                emit chatAddSignal(cur);
            }
            if (cmd == "ADDFRIENDSUCCEES")
            {
                addFriendSucceed(cur);
            }
            if (cmd == "REMOVESUCCEES")
            {
                emit removeSucceedSignal(cur);
            }
            if (cmd == "USERINFO")
            {
                emit fleshUserSignal(cur);
            }
        }
    }
}
void client::addFriendSucceed(QString init)
{
    qDebug() << "add" << init;
    emit buildFriendSignal(userId,divide(init, DIV_CMD).toInt());
}
void client::loginSucceed(QString init)
{
    qDebug() << "comand" << init;
    if (init == "")return;
    QString temp = divide(init, DIV_CMD);
    userId = temp.toInt();
    userName = divide(init, DIV_CMD);;
    while (init != ""){
        QString friendStr = divide(init, INF_CMD);

        emit buildFriendSignal(userId, friendStr.toInt());
    }
}
qint32 client::sendMessageSlot(QString init)
{
    qDebug() << "send:" << init << endl;
    //thisSock.write("114514");
    thisSock.write((QString::number(curId) + DIV_CMD + init + END_CMD).toLocal8Bit());
    return curId++;
}
qint32 client::sendMessageSlot(QString comand, QString init)
{
    qDebug() << "send:" << init << endl;
    //thisSock.write("114514");
    thisSock.write((QString::number(curId) + DIV_CMD + comand + DIV_CMD + init + END_CMD).toLocal8Bit());
    return curId++;
}
