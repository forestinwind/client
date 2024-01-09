#include "chatwidgets.h"
#include "ui_chatwidgets.h"
#include "chatwidget.h"
#include "..\shared\shared.h"

#include <qdebug.h>

chatWidgets::chatWidgets(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chatWidgets)
{
    qDebug() << "widget created"<<&friends;
    ui->setupUi(this);
}

chatWidgets::~chatWidgets()
{
    delete ui;
}
void chatWidgets::buildFriendSlot(QString info)
{
   /* qDebug() << ":" << info;
    chatWidget* thisWidget = new chatWidget(info, this);
    connect(thisWidget, &chatWidget::sendMessageSignal, this, &chatWidgets::sendMessageSlot);
    friends[thisWidget->FID] = thisWidget;
    thisWidget->construct();
    ui->tabWidget->addTab(thisWidget, thisWidget->friendName);*/
}
chatWidget* chatWidgets::buildFriend(qint32 sid, qint32 fid, qint32 friendid, QString name)
{
    friends;
    qDebug() << "debug3" << &friends;
    chatWidget* thisWidget;
    if (friends[fid] != nullptr);
    else thisWidget = new chatWidget(sid, fid, friendid, name, this);
    connect(thisWidget, &chatWidget::sendMessageSignal, this, &chatWidgets::sendMessageSlot);
    friends[thisWidget->FID] = thisWidget;
    thisWidget->construct();
    ui->tabWidget->addTab(thisWidget, thisWidget->friendName);
    return thisWidget;
}
void chatWidgets::showChatWidgetSlot()
{
    this->show();
}
void chatWidgets::addTab(chatWidget* init)
{
    qDebug() << "add";
    friends[init->FID] = init;
    ui->tabWidget->addTab(init, init->friendName);
}
qint32 chatWidgets::sendMessageSlot(QString init)
{
    return emit sendMessageSignal(init);
}
void chatWidgets::chatRecordSlot(QString init)
{
    qDebug() << "s:" << init;
    chatWidget* thisWidget = friends[divide(init, DIV_CMD).toInt()];
    qDebug() << "s:" << init;
    thisWidget->chatReflesh(init);
}
void chatWidgets::chatAddSlot(QString init)
{
    chatWidget* thisWidget = friends[divide(init, DIV_CMD).toInt()];
    thisWidget->chatAdd(init);
}
void chatWidgets::on_tabWidget_tabCloseRequested(int index)
{
    chatWidget *curWidget = dynamic_cast<chatWidget*>(ui->tabWidget->widget(index));
    friends.remove(curWidget->FID);
    ui->tabWidget->removeTab(index);
}

