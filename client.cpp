#include <qdebug.h>
#include "client.h"

#define IPLOC "172.16.180.11"
#define SERVER_PORT 40004

client::client() 
{
    connect(&thisSock, &QTcpSocket::readyRead, this, &client::readSockSlot);
}
bool client::begin()//connectδ�������Ҳ��ܽ����ϴ��ݵ��ź��ڹ��캯������
{
    thisSock.connectToHost(QHostAddress(IPLOC), SERVER_PORT);
    thisSock.write("michael");
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
    if (!buffer.isEmpty())
    {
        QString str = tr(buffer);
        writeBrowserSignal(str);
    }
}
void client::sendMessageSlot(QString init)
{
    thisSock.write(init.toUtf8());
}
