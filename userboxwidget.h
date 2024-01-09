#pragma once

#include <QWidget>
#include <qevent.h>

#include "userlistwidget.h"
#include "chatwidget.h"
#include "chatwidgets.h"

namespace Ui {
class userBoxWidget;
}

class userBoxWidget : public QWidget
{
    Q_OBJECT

public:
    explicit userBoxWidget(QString info, QWidget* parent = nullptr);
    ~userBoxWidget();
    void createChatWidget();

private:
    Ui::userBoxWidget *ui;
    qint32 friendId;
    qint32 FID;
    qint32 SID;
    QString friendName;
public:
    chatWidget* thisChatWidget;
};

