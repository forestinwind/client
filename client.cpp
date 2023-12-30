#include <qdebug.h>
#include "client.h"

#define IPLOC "127.0.0.1"
#define SERVER_PORT 40004

client::client() 
{
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
    if (!buffer.isEmpty())
    {
        QString str = tr(buffer);

        writeBrowserSignal(str);
    }
}
int client::sendMessageSlot(QString init)
{
    qDebug()<<init<<endl;
    //thisSock.write("114514");
    thisSock.write((QString::number(curId) +" " + init + "\r\n").toLocal8Bit());
    return curId++;
}
