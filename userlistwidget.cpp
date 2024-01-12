#include "userlistwidget.h"
#include "ui_userlistwidget.h"
#include "..\shared\shared.h"

#include <qicon.h>


userListWidget::userListWidget(QWidget *parent)
    : QListWidget(parent)
    , ui(new Ui::userListWidget)
{
    ui->setupUi(this);
    thischatwidget = new chatWidgets();

 //   connect(thischatwidget, SIGNAL(sendMessageSignal(QString)), this, SLOT(sendMessageSignal(QString)));
    ovoitem = addClass("你的好友");

    friendMenu = new QMenu;

    QAction* removeFriend = new QAction("删除好友", this);

    friendMenu->addAction(removeFriend);

    connect(removeFriend, SIGNAL(triggered()), this, SLOT(deletefriendslot()));

}

userListWidget::~userListWidget()
{
    delete ui;
}

void userListWidget::buildFriendSlot(QString init)
{
    QListWidgetItem* item = new QListWidgetItem();
    addItem(item);
    //ovo->setSizeIncrement(thissize.width(), 56);
    userBoxWidget* thisbox = new userBoxWidget(init, this);
    thisbox->createChatWidget();
    setItemWidget(item, thisbox);
    itemToBox[item] = thisbox;
    QSize thissize = thisbox->sizeHint();
    item->setSizeHint(QSize(thissize.width(), thissize.height()));
    itemParMap[item] = ovoitem;
}


QListWidgetItem* userListWidget::addClass(QString kind)
{
    QIcon thisicon = qiconFromSvg("../shared/icon/down.svg", "blue");
    QListWidgetItem* item = new QListWidgetItem(thisicon, kind);
    item->setSizeHint(QSize(this->width(), 40));
    addItem(item);
    itemParMap[item] = item;
    itemShowMap[item] = true;
    return item;
}

void userListWidget::mousePressEvent(QMouseEvent *event)//listwidgetitem是纯数据类
{
    QListWidget::mousePressEvent(event);
    qDebug() << "clicked1";
    curItem = this->itemAt(mapFromGlobal(QCursor::pos()));
    if (curItem == nullptr)
    {
        return;
    }
    if (itemParMap.value(curItem) == curItem)
    {
        itemShowMap[curItem] = !itemShowMap[curItem];
        QIcon thisicon;
        if (itemShowMap.value(curItem))thisicon = qiconFromSvg("../shared/icon/down.svg", "blue");
        else
        {
            thisicon = qiconFromSvg("../shared/icon/right.svg", "red");
        }
        for each (QListWidgetItem* friendItem in itemParMap.keys(curItem)){
            if(friendItem != curItem){
                friendItem->setHidden(!itemShowMap.value(curItem));
            }
        }
        curItem->setIcon(thisicon);
    }
}
void userListWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QListWidget::contextMenuEvent(event);
    if (curItem == itemParMap.value(curItem));
    else
    {
        friendMenu->exec(QCursor::pos());
    }
}

void userListWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    QListWidget::mouseDoubleClickEvent(event);
    qDebug() << "clicked2";
    curItem = this->itemAt(mapFromGlobal(QCursor::pos()));
    if(curItem == nullptr)
    {
        return;
    }
    if(itemParMap[curItem] != curItem)
    {
        thischatwidget->addTab(itemToBox.value(curItem)->thisChatWidget);
        thischatwidget->show();
        thischatwidget->raise();
    }
}
void userListWidget::deletefriendslot()
{
    qDebug() << "delete";
    itemToBox.value(curItem)->deleteFriend();
}