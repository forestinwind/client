#pragma once

#include <qtcpsocket.h>
#include <qhostaddress.h>
#include <qobject.h>


class client:public QObject
{
    Q_OBJECT

public:
    client();
    bool begin();
    QTcpSocket thisSock;
private:
public slots:
    void readSockSlot();
    void sendMessageSlot(QString);
signals:
    void writeBrowserSignal(QString);
};

