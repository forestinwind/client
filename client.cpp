#include <qdebug.h>

#include "client.h"
#include "..\shared\shared.h"

#define IPLOC "127.0.0.1"
#define SERVER_PORT 40004

client::client() 
{
    userId = -1;
    connect(&thisSock, &QTcpSocket::readyRead, this, &client::readSockSlot);
    curId = 0;
}
client::~client()
{
    sendMessageSlot("LOGOUT");
}
bool client::begin()//connectδ�������Ҳ��ܽ����ϴ��ݵ��ź��ڹ��캯������
{
    thisSock.connectToHost(QHostAddress(IPLOC), SERVER_PORT);
    //thisSock.write("michael");
    if (thisSock.waitForConnected(5000))
    {
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
        QString cur;
        while ((cur = divide(str, END_CMD)) != "")
        {
            qDebug("??");
            emit writeBrowserSignal(cur);//������error��ԭ��������������Ϊ_CMD�ָ��
            qDebug("???");
            int cmdid = divide(cur, DIV_CMD).toInt(); //����id����Ҫ�ȴ���Ӧ

            QString cmd = divide(cur, DIV_CMD);
            if(cmd=="LOGINSUCCEES")
            {
                loginSucceed(cur);
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
        }
    }
}
void client::loginSucceed(QString init)
{   
    userId = divide(init, DIV_CMD).toInt();
    while (init != ""){
        QString friendStr = divide(init, INF_CMD);
        emit buildFriendSignal(friendStr);
    }
}

qint32 client::sendMessageSlot(QString init)
{
    qDebug()<<init<<endl;
    //thisSock.write("114514");
    thisSock.write((QString::number(curId) + DIV_CMD + init + END_CMD).toLocal8Bit());
    return curId++;
}
