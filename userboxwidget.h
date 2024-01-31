#pragma once

#include <QWidget>
#include <qevent.h>

#include "chatwidget.h"
#include "chatwidgets.h"

namespace Ui {
class userBoxWidget;
}
class userListWidget;
class userBoxWidget : public QWidget
{
    Q_OBJECT

public:
    explicit userBoxWidget(qint32, qint32, QWidget* parent = nullptr);
    ~userBoxWidget();
    void deleteFriend();
    chatWidget* thisChatWidget;
    void cmdFromClient(QString, QString);
    void changeHead(QPixmap);
    void changeSign(QString);
    qint32 FID;
    qint32 SID;

private:
    void fleshUser(QString);
    Ui::userBoxWidget *ui;
    QString friendName;
    QString signStr;
    userListWidget* par;

};

