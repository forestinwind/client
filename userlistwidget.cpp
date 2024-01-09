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
    ovoitem = addClass("你的好友");
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
    qDebug() << "clicked1";
    QListWidgetItem* curItem = this->itemAt(mapFromGlobal(QCursor::pos()));
    if (curItem == nullptr)
    {
        return;
    }
    if (itemParMap[curItem] == curItem)
    {
        itemShowMap[curItem] = !itemShowMap[curItem];
        QIcon thisicon;
        if (itemShowMap[curItem])thisicon = qiconFromSvg("../shared/icon/down.svg", "blue");
        else
        {
            thisicon = qiconFromSvg("../shared/icon/right.svg", "red");
        }
        for each (QListWidgetItem* friendItem in itemParMap.keys(curItem)){
            if(friendItem != curItem){
                friendItem->setHidden(!itemShowMap[curItem]);
            }
        }
        curItem->setIcon(thisicon);
    }
}
void userListWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "clicked2";
    QListWidgetItem* curItem = this->itemAt(mapFromGlobal(QCursor::pos()));
    if(curItem == nullptr)
    {
        return;
    }
    if(itemParMap[curItem] != curItem)
    {
        thischatwidget->addTab(itemToBox[curItem]->thisChatWidget);
    }
}