#include "userboxwidget.h"
#include "ui_userboxwidget.h"
#include "..\shared\shared.h"

#include <qdebug.h>

userBoxWidget::userBoxWidget(QString info,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::userBoxWidget)
{
    ui->setupUi(this);


    SID = divide(info, DIV_CMD).toInt();
    FID = divide(info, DIV_CMD).toInt();
    friendId = divide(info, DIV_CMD).toInt();
    friendName = info;
    ui->userNamelabel->setText(friendName);
    ui->selfSignlabel->setText(QString::number(SID) + QString::number(FID));
}

userBoxWidget::~userBoxWidget()
{
    delete ui;

}

void userBoxWidget::createChatWidget()
{
    qDebug() << "debug1";
    //chatWidget* newchatwidget = parChatWidgets->buildFriend(SID, FID, friendId, friendName);
    thisChatWidget =
        (dynamic_cast<userListWidget*>(parentWidget()))->thischatwidget->buildFriend(SID, FID, friendId, friendName);   
    qDebug() << "debug2";
}


