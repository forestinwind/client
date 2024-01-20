#include "chatwidgets.h"
#include "ui_chatwidgets.h"
#include "chatwidget.h"
#include "..\shared\shared.h"

#include <qdebug.h>

chatWidgets::chatWidgets(QWidget *parent)
    : QTabWidget(parent)
{
    this->resize(QSize(800, 600));
    this->setTabsClosable(true);
    connect(this, SIGNAL(tabCloseRequested(qint32)), this, SLOT(on_tabWidget_tabCloseRequested(qint32)));
    qDebug() << "widget created"<<&friends;
    //ui->setupUi(this);
}

chatWidgets::~chatWidgets()
{
}
chatWidget* chatWidgets::buildFriend(qint32 sid, qint32 fid)
{
    chatWidget* thisWidget;
    if (friends[fid] != nullptr)thisWidget = friends[fid];
    else thisWidget = new chatWidget(sid, fid, this);
    friends[thisWidget->FID] = thisWidget;
    thisWidget->construct();
    this->addTab(thisWidget, thisWidget->friendName);
    return thisWidget;
}
void chatWidgets::showChatWidgetSlot()
{
    this->show();
}
void chatWidgets::buildTab(chatWidget* init)
{
    qDebug() << "add";
    friends[init->FID] = init;
    this->addTab(init, init->friendName);
}
void chatWidgets::showTab(chatWidget* init) 
{
    buildTab(init);
    this->show();
    this->raise();
    this->setCurrentWidget(init);
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
    if (thisWidget != nullptr)thisWidget->chatAdd(init);
}
void chatWidgets::on_tabWidget_tabCloseRequested(qint32 index)
{
    chatWidget *curWidget = dynamic_cast<chatWidget*>(this->widget(index));
    friends.remove(curWidget->FID);
    this->removeTab(index);
}
void chatWidgets::deleteChatWidgetSlot(qint32 index)
{
    friends.remove(index);
}

