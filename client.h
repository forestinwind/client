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
    qint32 curId;
    qint32 userId;
    void loginSucceed(QString);
public slots:
    void readSockSlot();
    qint32 sendMessageSlot(QString);
signals:
    void writeBrowserSignal(QString);
    void buildFriendSignal(QString);
    void showChatWidgetSignal();
    void chatRecordSignal(QString);
    void chatAddSignal(QString);
};

