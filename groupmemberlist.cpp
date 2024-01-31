#include "groupmemberlist.h"
#include "..\shared\shared.h"
#include <qdebug.h>

groupMemberlist::groupMemberlist(QWidget* parent) 
{
    connect(this, SIGNAL(sendMessageSignal(QString, QString)), parent, SIGNAL(sendMessageSignal(QString, QString)));
    connect(this, SIGNAL(sendMessageSignal(QString, QString)), parent, SIGNAL(sendMessageSignal(QString, QString)));

    hostitem = addClass("舰长");
    adminitem = addClass("大副");
    guestitem = addClass("一般船员");
    joinitem = addClass("请求加入");
    curItem = nullptr;
    joinitem->setHidden(true);

    selfMenu = new QMenu;
    adminMenu = new QMenu;
    guestMenu = new QMenu;
    joinMenu = new QMenu;


}
groupMemberlist::~groupMemberlist()
{
    disconnect();
    itemParMap.clear();
    itemToID.clear();
    itemShowMap.clear();
    IDtoItem.clear();
    IDtoBox.clear();
    this->clear();
}
void groupMemberlist::setPower()
{
    if (selfMenu != nullptr) { delete selfMenu; selfMenu = nullptr; }
    if (adminMenu != nullptr) { delete adminMenu; adminMenu = nullptr; }
    if (guestMenu != nullptr) { delete guestMenu; guestMenu = nullptr; }
    if (joinMenu != nullptr) { delete joinMenu; joinMenu = nullptr; }
    selfMenu = new QMenu;
    adminMenu = new QMenu;
    guestMenu = new QMenu;
    joinMenu = new QMenu;
    QAction* allowJoin = new QAction("允许加入", this);
    QAction* refuseJoin = new QAction("拒绝加入", this);
    QAction* quitGroup = new QAction("退出群聊", this);
    QAction* kickMember = new QAction("踢出群聊", this);
    QAction* setAdmin = new QAction("设为管理员", this);
    QAction* cancelAdmin = new QAction("取消管理员", this);

    connect(allowJoin, SIGNAL(triggered()), this, SLOT(allowJoinSlot()));
    connect(refuseJoin, SIGNAL(triggered()), this, SLOT(kickMemberSlot()));
    connect(quitGroup, SIGNAL(triggered()), this, SLOT(quitGroupSlot()));
    connect(kickMember, SIGNAL(triggered()), this, SLOT(kickMemberSlot()));
    connect(setAdmin, SIGNAL(triggered()), this, SLOT(setAdminSlot()));
    connect(cancelAdmin, SIGNAL(triggered()), this, SLOT(cancelAdminSlot()));
    if (thisLevel == 1)
    {
        selfMenu->addAction(kickMember);

        adminMenu->addAction(kickMember);
        adminMenu->addAction(cancelAdmin);

        guestMenu->addAction(kickMember);
        guestMenu->addAction(setAdmin);

        joinMenu->addAction(allowJoin);
        joinMenu->addAction(refuseJoin);

    }
    if (thisLevel == 2)
    {
        selfMenu->addAction(kickMember);

        guestMenu->addAction(kickMember);

        joinMenu->addAction(allowJoin);
    }
    if (thisLevel == 3)
    {
        selfMenu->addAction(kickMember);
    }
}

QListWidgetItem* groupMemberlist::addClass(QString kind)
{
    QPixmap thisicon = qPixmapFromSvg("icon/down.svg", "blue");
    QListWidgetItem* item = new QListWidgetItem(thisicon, kind);
    item->setSizeHint(QSize(this->width(), 40));
    addItem(item);
    itemParMap[item] = item;
    itemShowMap[item] = true;
    return item;
}

void groupMemberlist::createItem(QString init)
{
    QString temp = init;
    QListWidgetItem* item = new QListWidgetItem();
    
    qint32 level = divide(init).toInt();
    qint32 thisID = divide(init).toInt();
    qDebug() << "thisID" << thisID<<IDtoItem[thisID];
    delete IDtoItem[thisID];
    delete IDtoBox[thisID];
    
    if (level == 1)
    {
        itemParMap[item] = hostitem;
        this->insertItem(row(hostitem) + 1, item);
    }
    else if (level == 2)
    {
        itemParMap[item] = adminitem;
        this->insertItem(row(adminitem) + 1, item);
    }
    else if (level == 3)
    {
        itemParMap[item] = guestitem;
        this->insertItem(row(guestitem) + 1, item);
    }
    else
    {
        if (thisLevel > 2) return;
        itemParMap[item] = joinitem;
        this->insertItem(row(joinitem) + 1, item);
    }
    memberBoxWidget* thisbox = new memberBoxWidget(temp, this);
    setItemWidget(item, thisbox);
    QSize thissize = thisbox->sizeHint();
    item->setSizeHint(QSize(thissize.width(), thissize.height()));
    itemToID[item] = thisID;
    itemShowMap[item] = true;
    IDtoItem[thisID] = item;
    IDtoBox[thisID] = thisbox;
    qDebug() << "this" <<thisID<< this<<row(item)<<thisbox<<IDtoBox[thisID];
    if (thisID == SID)
    {
        thisLevel = level;
        setPower();
        joinitem->setHidden(true);

        if (thisLevel == 2)
        {
            joinitem->setHidden(false);
        }
        if (thisLevel == 1)
        {
            joinitem->setHidden(false);
        }
    }
    IDtoName[thisID] = divide(init);
}

void groupMemberlist::mousePressEvent(QMouseEvent* event)
{
    QListWidget::mousePressEvent(event);
    curItem = this->itemAt(mapFromGlobal(QCursor::pos()));
    if (curItem == nullptr)
    {
        return;
    }
    if (itemParMap.value(curItem) == curItem)
    {
        itemShowMap[curItem] = !itemShowMap[curItem];
        QIcon thisicon;
        if (itemShowMap.value(curItem))thisicon = qPixmapFromSvg("icon/down.svg", "blue");
        else
        {
            thisicon = qPixmapFromSvg("icon/right.svg", "red");
        }
        for each (QListWidgetItem * friendItem in itemParMap.keys(curItem)) {
            if (friendItem != curItem) {
                friendItem->setHidden(!itemShowMap.value(curItem));
            }
        }
        curItem->setIcon(thisicon);
    }
}
void groupMemberlist::mouseDoubleClickEvent(QMouseEvent* event)
{
    QListWidget::mouseDoubleClickEvent(event);
}
void groupMemberlist::contextMenuEvent(QContextMenuEvent* event)
{
    QListWidget::contextMenuEvent(event);
    if (itemParMap.value(curItem) == curItem) return;
    if (itemToID.value(curItem) == SID)
    {
        selfMenu->exec(QCursor::pos());
        return;
    }
    if (itemParMap.value(curItem) == joinitem)
    {
        joinMenu->exec(QCursor::pos());
        return;
    }
    if (itemParMap.value(curItem) == guestitem)
    {
        guestMenu->exec(QCursor::pos());
        return;
    }
    if (itemParMap.value(curItem) == adminitem)
    {
        adminMenu->exec(QCursor::pos());
        return;
    }
}
void groupMemberlist::kickMemberSlot()
{
    emit sendMessageSignal("QUITGROUP", QString::number(GID) + DIV_CMD + QString::number(itemToID[curItem]));
}
void groupMemberlist::allowJoinSlot()
{
    emit sendMessageSignal("GROUP_MEMEBRLEVELSET", QString::number(GID) + DIV_CMD + QString::number(itemToID[curItem]) + DIV_CMD + "3");
}
void groupMemberlist::setAdminSlot()
{
    emit sendMessageSignal("GROUP_MEMEBRLEVELSET", QString::number(GID) + DIV_CMD + QString::number(itemToID[curItem]) + DIV_CMD + "2");
}
void groupMemberlist::cancelAdminSlot()
{
    emit sendMessageSignal("GROUP_MEMEBRLEVELSET", QString::number(GID) + DIV_CMD + QString::number(itemToID[curItem]) + DIV_CMD + "3");
}