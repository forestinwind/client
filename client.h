#pragma once

#include <qtcpsocket.h>
#include <qhostaddress.h>
#include <qobject.h>


class client:public QObject
{
    Q_OBJECT

public:
    client();
    ~client();
    bool begin();
    QTcpSocket thisSock;
private:
    int curId;
public slots:
    void readSockSlot();
    int sendMessageSlot(QString);
signals:
    void writeBrowserSignal(QString);
};

