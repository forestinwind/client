#include "chatwidgets.h"
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
    if (friends.value(fid) != nullptr)thisWidget = friends[fid];
    else thisWidget = new chatWidget(sid, fid, this);
    friends[thisWidget->FID] = thisWidget;

    this->addTab(thisWidget, thisWidget->friendName);
    return thisWidget;
}
groupChatWidget* chatWidgets::buildGroup(qint32 sid, qint32 gid)
{
    groupChatWidget* thisWidget;
    if (groups.value(gid) != nullptr)
    {
        qDebug() << "exist";
        thisWidget = groups[gid];
    }
    else thisWidget = new groupChatWidget(sid, gid, this);
    groups[thisWidget->GID] = thisWidget;

    this->addTab(thisWidget, thisWidget->groupName);
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
void chatWidgets::buildTab(groupChatWidget* init)
{
    qDebug() << "add";
    groups[init->GID] = init;
    this->addTab(init, init->groupName);
}
void chatWidgets::showTab(groupChatWidget* init)
{
    buildTab(init);
    this->show();
    this->raise();
    this->setCurrentWidget(init);
}
void chatWidgets::on_tabWidget_tabCloseRequested(qint32 index)
{
    if (this->widget(index)->metaObject()->className() == QString("chatWidget"))
    {
        qDebug() << "remove1";
        chatWidget* curWidget = dynamic_cast<chatWidget*>(this->widget(index));
        friends.remove(curWidget->FID);
    }
    if (this->widget(index)->metaObject()->className() == QString("groupChatWidget")) 
    {
        qDebug() << "remove2";
        groupChatWidget* curWidget = dynamic_cast<groupChatWidget*>(this->widget(index));
        groups.remove(curWidget->GID);
    }
    this->removeTab(index);
}
void chatWidgets::deleteChatWidgetSlot(qint32 index)
{
    friends.remove(index);
}
void chatWidgets::deleteGroupWidgetSlot(qint32 index)
{
    qDebug() << "ovo";
    groups.remove(index);
}

