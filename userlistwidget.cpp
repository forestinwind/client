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
    addClass("Default");
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
    QSize thissize = thisbox->sizeHint();
    item->setSizeHint(QSize(thissize.width(), thissize.height()));

}


void userListWidget::addClass(QString kind)
{
    QIcon* thisicon = qiconFromSvg("../shared/icon/down.svg", "red");
    QListWidgetItem* item = new QListWidgetItem(*thisicon, "̫你的好友");
    item->setSizeHint(QSize(this->width(), 40));
    addItem(item);
    itemParMap[item] = item;
    itemShowMap[item] = true;
}

