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
    QString thisBuffer;
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
    void logFailCMDSignal(QString);
    void writeBrowserSignal(QString);
    void buildFriendSignal(qint32, qint32);
    void buildGroupSignal(qint32, qint32);
    void showChatWidgetSignal();
    void chatAddSignal(QString);
    void closeLoginWidgetSignal();
    void removeSucceedSignal(QString);
    void quitGroupSignal(QString);
    void forwardToGroupSignal(QString, QString);
    void forwardToUserSignal(QString, QString);
};

