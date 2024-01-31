#include "userlistwidget.h"
#include "ui_userlistwidget.h"
#include "..\shared\shared.h"

#include <qicon.h>
#include <qfiledialog.h>
#include <qinputdialog.h>
#include <qbuffer.h>


userListWidget::userListWidget(QWidget *parent)
    : QListWidget(parent)
    , ui(new Ui::userListWidget)
{
    ui->setupUi(this);
    thischatwidget = new chatWidgets();

 //   connect(thischatwidget, SIGNAL(sendMessageSignal(QString)), this, SLOT(sendMessageSignal(QString)));
    youitem = addClass("宁");
    frienditem = addClass("你的好友");
    groupitem = addClass("宁的群聊");

    friendMenu = new QMenu;
    yourMenu = new QMenu;
    groupMenu = new QMenu;

    QAction* removeFriend = new QAction("删除好友", this);
    QAction* changeHead = new QAction("更换头像", this);
    QAction* changeSign = new QAction("重写签名", this);

    friendMenu->addAction(removeFriend);
    yourMenu->addAction(changeHead);
    yourMenu->addAction(changeSign);

    connect(removeFriend, SIGNAL(triggered()), this, SLOT(deletefriendSlot()));
    connect(changeHead, SIGNAL(triggered()), this, SLOT(changeHeadSlot()));
    connect(changeSign, SIGNAL(triggered()), this, SLOT(changeSignSlot()));

}

userListWidget::~userListWidget()
{
    delete ui;
}
void userListWidget::buildGroupSlot(qint32 sid, qint32 gid)
{
    buildGroupFunc(groupitem, sid, gid);
}
void userListWidget::buildGroupFunc(QListWidgetItem* par, qint32 sid, qint32 gid)
{
    qDebug() <<"group" << sid << gid;
    if (GIDtoitem.value(gid) != nullptr) return;
    if (GIDtobox.value(gid) != nullptr) return;
    QListWidgetItem* item = new QListWidgetItem();
    insertItem(row(par) + 1, item);
    groupBoxWidget* thisbox = new groupBoxWidget(sid, gid, this);
    GIDtoitem[gid] = item;
    GIDtobox[gid] = thisbox;
    itemToGroupBox[item] = thisbox;
    itemParMap[item] = par;
    setItemWidget(item, thisbox);
    QSize thissize = thisbox->sizeHint();
    item->setSizeHint(QSize(thissize.width(), thissize.height()));

}
void userListWidget::buildFriendSlot(qint32 sid, qint32 fid)
{
    if(sid != fid)buildFriendFunc(frienditem, sid, fid);
    else buildFriendFunc(youitem, sid, fid);
}

void userListWidget::buildFriendFunc(QListWidgetItem* par, qint32 sid, qint32 fid)
{
    
    qDebug()<<"build" << sid << fid;

    if (SIDtoitem.value(fid) != nullptr) return;
    QListWidgetItem* item = new QListWidgetItem();
//    addItem(item);
    insertItem(row(par) + 1, item);
    //ovo->setSizeIncrement(thissize.width(), 56);
    userBoxWidget* thisbox = new userBoxWidget(sid, fid, this);

//    thisbox->createChatWidget(); 已废弃

    //item的构造
    SIDtoitem[fid] = item;
    SIDtobox[fid] = thisbox;
    itemToUserBox[item] = thisbox;
    itemParMap[item] = par;
    setItemWidget(item, thisbox);
    QSize thissize = thisbox->sizeHint();
    item->setSizeHint(QSize(thissize.width(), thissize.height()));
}
void userListWidget::forwardToGroupSlot(QString cmd, QString init) //注：转发对象已知GID，故可以舍去
{
    qDebug ()<< init;
    QString id = divide(init, DIV_CMD);
    if (id == "" || GIDtobox.value(id.toInt()) == nullptr)return;
    GIDtobox[id.toInt()]->cmdFromClient(cmd, init);
}
void userListWidget::forwardToUserSlot(QString cmd, QString init)
{
    QString id = divide(init, DIV_CMD);
    if (id == "" || SIDtobox.value(id.toInt()) == nullptr)return;
    SIDtobox[id.toInt()]->cmdFromClient(cmd, init);
}


void userListWidget::changeSignSlot()
{
    bool used;
    QString newSign = QInputDialog::getText(this, "宁的签名", "宁的签名是：",QLineEdit::Normal,"",&used,
        Qt::SplashScreen);
    this->activateWindow();
    if (used) 
    {

        newSign = escape(newSign);

        itemToUserBox[curItem]->changeSign(newSign);
        emit sendMessageSignal("CHANGEINFO", "sign" + DIV_CMD + newSign);
    }
    else qDebug() << "unUSE";
}
void userListWidget::changeHeadSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("选择图片"),
        QDir::currentPath(),
        tr("images(*.png *.jpeg *.bmp *.jpg);;All files(*.*)"));
    QPixmap newpix;
    if (newpix.load(fileName))
    {
        newpix = newpix.scaled(64, 64, Qt::KeepAspectRatio);
        itemToUserBox[curItem]->changeHead(newpix);
        
        QByteArray tempArray;
        QBuffer buffer(&tempArray);
        buffer.open(QIODevice::WriteOnly);
        newpix.save(&buffer, "PNG");

        QString headStr = tempArray.toBase64();

        emit sendMessageSignal("CHANGEINFO", "head" + DIV_CMD + escape(headStr));
    }
}


QListWidgetItem* userListWidget::addClass(QString kind)
{
    QPixmap thisicon = qPixmapFromSvg("icon/down.svg", "blue");
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
        if (itemShowMap.value(curItem))thisicon = qPixmapFromSvg("icon/down.svg", "blue");
        else
        {
            thisicon = qPixmapFromSvg("icon/right.svg", "red");
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
        if (itemParMap[curItem] == frienditem)friendMenu->exec(QCursor::pos());
        if (itemParMap[curItem] == youitem)yourMenu->exec(QCursor::pos());
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
        if (itemParMap[curItem] == frienditem || itemParMap[curItem] == youitem)
        {
            thischatwidget->showTab(itemToUserBox.value(curItem)->thisChatWidget);
        }
        if (itemParMap[curItem] == groupitem)
        {
            thischatwidget->showTab(itemToGroupBox.value(curItem)->thisChatWidget);
        }
    }
}
void userListWidget::deletefriendSlot()
{
    qDebug() << "delete";
    
    itemToUserBox.value(curItem)->deleteFriend();
    //
}
void userListWidget::removeSucceedSlot(QString init)
{

    int friendID = divide(init, DIV_CMD).toInt();

    qDebug() << "try delete" <<friendID;

    delete SIDtoitem[friendID];//在这个过程中，我调用了box的析构函数，说明其已被释放，原因不明

}
void userListWidget::quitGroupSlot(QString init)
{
    int GID = init.toInt();
    qDebug() << "remove" << GID;
    delete GIDtoitem[GID];
}
void userListWidget::DeleteUser(qint32 uid)
{
    QListWidgetItem* thisItem = SIDtoitem[uid];
    SIDtobox.remove(uid);
    SIDtoitem.remove(uid);
    itemParMap.remove(thisItem);
    itemShowMap.remove(thisItem);
    itemToUserBox.remove(thisItem);
}
void userListWidget::DeleteGroup(qint32 gid)
{
    QListWidgetItem* thisItem = GIDtoitem[gid];
    GIDtobox.remove(gid);
    GIDtoitem.remove(gid);
    itemParMap.remove(thisItem);
    itemShowMap.remove(thisItem);
    itemToGroupBox.remove(thisItem);
}