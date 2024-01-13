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
    explicit userBoxWidget(QString info, QWidget* parent = nullptr);
    ~userBoxWidget();
    void createChatWidget();
    void deleteFriend();
    qint32 FID;
    qint32 SID;

private:
    Ui::userBoxWidget *ui;
    QString friendName;
public:
    chatWidget* thisChatWidget;
};

