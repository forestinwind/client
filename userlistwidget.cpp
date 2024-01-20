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

    friendMenu = new QMenu;
    yourMenu = new QMenu;

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

void userListWidget::buildFriendSlot(qint32 sid, qint32 fid)
{
    if(sid != fid)buildFriendFunc(frienditem, sid, fid);
    else buildFriendFunc(youitem, sid, fid);
}

void userListWidget::buildFriendFunc(QListWidgetItem* par, qint32 sid, qint32 fid)
{
    
    qDebug()<<"build" << sid << fid;

    if (IDtoitem.value(fid) != nullptr) return;
    QListWidgetItem* item = new QListWidgetItem();
//    addItem(item);
    insertItem(row(par) + 1, item);
    //ovo->setSizeIncrement(thissize.width(), 56);
    userBoxWidget* thisbox = new userBoxWidget(sid, fid, this);

//    thisbox->createChatWidget(); 已废弃

    //item的构造
    IDtoitem[fid] = item;
    IDtobox[fid] = thisbox;
    itemToBox[item] = thisbox;
    itemParMap[item] = par;
    setItemWidget(item, thisbox);
    QSize thissize = thisbox->sizeHint();
    item->setSizeHint(QSize(thissize.width(), thissize.height()));
}

void userListWidget::fleshUserSlot(QString init)
{
    QString id = divide(init, DIV_CMD);
    qDebug() << "flesh1:" <<id<< init;
    if (id=="")return;
    IDtobox[id.toInt()]->fleshUser(init);
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

        itemToBox[curItem]->changeSign(newSign);
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
        itemToBox[curItem]->changeHead(newpix);
        
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
    QPixmap thisicon = qPixmapFromSvg("../shared/icon/down.svg", "blue");
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
        if (itemShowMap.value(curItem))thisicon = qPixmapFromSvg("../shared/icon/down.svg", "blue");
        else
        {
            thisicon = qPixmapFromSvg("../shared/icon/right.svg", "red");
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
        if (itemParMap[curItem] == frienditem)
        {
            thischatwidget->buildTab(itemToBox.value(curItem)->thisChatWidget);
            thischatwidget->showTab(itemToBox.value(curItem)->thisChatWidget);
        }
    }
}
void userListWidget::deletefriendSlot()
{
    qDebug() << "delete";
    
    itemToBox.value(curItem)->deleteFriend();
    //
}
void userListWidget::removeSucceedSlot(QString init)
{

    int friendID = divide(init, DIV_CMD).toInt();

    qDebug() << "try delete" <<friendID;

    QListWidgetItem* waitRemoveItem = IDtoitem[friendID];

    IDtobox.remove(friendID);
    IDtoitem.remove(friendID);
    this->takeItem(this->row(waitRemoveItem));
    itemParMap.remove(waitRemoveItem);
    itemShowMap.remove(waitRemoveItem);
    userBoxWidget* waitRemoveBox = itemToBox[waitRemoveItem];
    delete waitRemoveBox;
    itemToBox.remove(waitRemoveItem);
    delete waitRemoveItem;

}