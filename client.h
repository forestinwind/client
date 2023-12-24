#pragma once

#include <qtcpsocket.h>
#include <qhostaddress.h>
#include <qobject.h>

class client:public QObject
{
    Q_OBJECT

public:
    client();
    QTcpSocket thisSock;
private:
public slots:
    void begin();
    void readSock();
signals:
    void writeBrowser(QString);
};

