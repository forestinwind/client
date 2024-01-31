#include <qdebug.h>

#include "groupboxwidget.h"
#include "ui_groupboxwidget.h"
#include "..\shared\shared.h"
#include "userlistwidget.h"

groupBoxWidget::groupBoxWidget(qint32 sid, qint32 gid, QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::groupBoxWidget)
{
    qDebug() << "newGroupboxBeg";
    ui->setupUi(this);
    SID = sid;
    GID = gid;
    ui->groupSignlabel->setText(QString(SID) + QString(GID));
    par = dynamic_cast<userListWidget*>(parentWidget());
    thisChatWidget = par->thischatwidget->buildGroup(SID, GID);
    qDebug() << "newGroupbox";
}

groupBoxWidget::~groupBoxWidget()
{
    par->DeleteGroup(GID);
    delete thisChatWidget;
    delete ui;
}
void groupBoxWidget::cmdFromClient(QString cmd, QString init)
{
    if (cmd == "GROUPINFO")
    {
        fleshGroup(init);
        return;
    }
    if (cmd == "GROUPCHATRECORD")
    {
        thisChatWidget->chatReflesh(init);
        return;
    }
    if (cmd == "GROUPCHATADD")
    {
        thisChatWidget->messageGet(init);
        return;
    }
    qDebug() << cmd << init;
    if (cmd == "GROUP_MEMBERKICKED")
    {
        thisChatWidget->memberKick(init);
        return;
    }
    if (cmd == "GROUP_MEMBERINFO")
    {
        thisChatWidget->fleshMember(init);
        return;
    }
}
void groupBoxWidget::fleshGroup(QString init)
{
    groupName = divide(init, DIV_CMD);
    QString temp = divide(init, DIV_CMD);
    QByteArray tempArray = QByteArray::fromBase64(decrypt(temp).toLocal8Bit());
    signStr = divide(init, DIV_CMD);
    QPixmap thisPixmap;

    thisPixmap.loadFromData(tempArray);
    ui->head->setPixmap(thisPixmap);
    ui->groupNamelabel->setText(groupName);
    ui->groupSignlabel->setText(signStr);
    thisChatWidget->setName(groupName);
}