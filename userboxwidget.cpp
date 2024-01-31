#include "userboxwidget.h"
#include "ui_userboxwidget.h"
#include "..\shared\shared.h"
#include "userlistwidget.h"

#include <qdebug.h>

userBoxWidget::userBoxWidget(qint32 sid, qint32 fid, QWidget* parent) //这是好友列表的box
    : QWidget(parent)
    , ui(new Ui::userBoxWidget)
{
    ui->setupUi(this);
    this->ui->head->setPixmap(this->ui->head->pixmap()->scaled(64, 64, Qt::KeepAspectRatio));
    SID = sid;
    FID = fid;
    ui->selfSignlabel->setText(QString::number(FID)+ QString::number(SID));
    par = dynamic_cast<userListWidget*>(parentWidget());
    thisChatWidget = par->thischatwidget->buildFriend(SID, FID);

}

userBoxWidget::~userBoxWidget()
{
    par->DeleteUser(FID);
    delete thisChatWidget;
    delete ui;

}

void userBoxWidget::fleshUser(QString init)
{
    qDebug() <<"flesh:" <<SID<< init;
    friendName = divide(init, DIV_CMD);
    QString temp = divide(init, DIV_CMD);
    QByteArray tempArray = QByteArray::fromBase64(decrypt(temp).toLocal8Bit());
    signStr = divide(init, DIV_CMD);
    QPixmap thisPixmap;

    thisPixmap.loadFromData(tempArray);
    ui->head->setPixmap(thisPixmap);
    ui->userNamelabel->setText(friendName);
    ui->selfSignlabel->setText(signStr);

    thisChatWidget->setName(friendName);
 //   userListWidget* par = dynamic_cast<userListWidget*>(parentWidget());为什么
}


void userBoxWidget::deleteFriend()
{
    thisChatWidget->sendMessageSignal("REMOVE", QString::number(FID) + DIV_CMD + QString::number(SID) + DIV_CMD);
}
void userBoxWidget::changeHead(QPixmap init)
{
    this->ui->head->clear();
    this->ui->head->setPixmap(init);
}
void userBoxWidget::changeSign(QString newSign)
{
    signStr = newSign;
    this->ui->selfSignlabel->setText(newSign);
}

void userBoxWidget::cmdFromClient(QString cmd, QString init)
{
    if (cmd == "USERINFO")
    {
        fleshUser(init);
        return;
    }
    if (cmd == "CHATRECORD")
    {
        thisChatWidget->chatReflesh(init);
        return;
    }
    if (cmd == "CHATADD")
    {
        thisChatWidget->chatAdd(init);
        return;
    }
}
