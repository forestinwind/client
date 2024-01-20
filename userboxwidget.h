#pragma once

#include <QWidget>
#include <qevent.h>

#include "chatwidget.h"
#include "chatwidgets.h"

namespace Ui {
class userBoxWidget;
}

class userBoxWidget : public QWidget
{
    Q_OBJECT

public:
    explicit userBoxWidget(qint32, qint32, QWidget* parent = nullptr);
    ~userBoxWidget();
    void createChatWidget();
    void deleteFriend();
    chatWidget* thisChatWidget;
    void changeHead(QPixmap);
    void fleshUser(QString);
    void changeSign(QString);
    qint32 FID;
    qint32 SID;

private:
    Ui::userBoxWidget *ui;
    QString friendName;
    QString signStr;

};

