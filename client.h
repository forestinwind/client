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
    QString serverIP;
    QString userName;
    qint32 servetPort;
    qint32 curId;
    qint32 userId;
    void loginSucceed(QString);
    void addFriendSucceed(QString);
public slots:
    void readSockSlot();
    qint32 sendMessageSlot(QString);
    qint32 sendMessageSlot(QString, QString);
signals:
    void fleshUserSignal(QString);
    void writeBrowserSignal(QString);
    void buildFriendSignal(qint32, qint32);
    void showChatWidgetSignal();
    void chatRecordSignal(QString);
    void chatAddSignal(QString);
    void closeLoginWidgetSignal();
    void removeSucceedSignal(QString);
};

