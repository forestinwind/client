#include <qdatetime.h>

#include "chatwidgets.h"
#include "groupchatwidget.h"
#include "ui_groupchatwidget.h"
#include "..\shared\shared.h"

groupChatWidget::groupChatWidget(qint32 sid, qint32 gid, chatWidgets *parent)
    : QWidget(parent)
    , ui(new Ui::groupChatWidget)
{
    ui->setupUi(this);
    SID = sid;
    ui->listWidget->SID = sid;
    GID = gid;
    ui->listWidget->GID = gid;
    connect(this, SIGNAL(sendMessageSignal(QString, QString)), parent, SIGNAL(sendMessageSignal(QString, QString)));
    connect(this, SIGNAL(deleteGroupWidgetSignal(qint32)), parent, SLOT(deleteGroupWidgetSlot(qint32)));
    par = parent;
    sendMessageSignal("REQUESTGROUPINFO", QString::number(SID) + DIV_CMD + QString::number(GID) + DIV_CMD);
}

groupChatWidget::~groupChatWidget()
{
    delete ui;
    emit deleteGroupWidgetSignal(GID);
    par = nullptr;
}
void groupChatWidget::memberKick(QString id)
{
    if (ui->listWidget->IDtoItem.value(id.toInt()))
    {
        delete ui->listWidget->IDtoItem[id.toInt()];
        delete ui->listWidget->IDtoBox[id.toInt()];
    }
}
void groupChatWidget::chatReflesh(QString init)
{
    ui->textBrowser->clear();
    QString temp = divide(init, INF_CMD);
    while (temp != "")
    {
        messageGet(temp);
        temp = divide(init, INF_CMD);
    }
}
void groupChatWidget::fleshMember(QString init)
{
    init = divide(init, INF_CMD);
    ui->listWidget->createItem(init);
}
void groupChatWidget::setName(QString init)
{
    groupName = init;
    par->setTabText(par->indexOf(this), init);
}
void groupChatWidget::messageGet(QString init)
{
    qint32 thisID = divide(init).toInt();
    if (thisID == SID)
    {
        ui->textBrowser->append("<font color=\"blue\">" + ui->listWidget->IDtoName[thisID] + ":"+ toFormat(init) + "</font>");
    }
    else
    {
        ui->textBrowser->append("<font color=\"green\">" + ui->listWidget->IDtoName[thisID] + ":"+ toFormat(init) + "</font>");
    }
}

void groupChatWidget::on_SendButton_clicked()
{
    QDateTime curDatetime = QDateTime::currentDateTime();
    QString message = escape(this->ui->plainTextEdit->toPlainText());
    emit sendMessageSignal("SENDGROUPCHAT", QString::number(GID) + DIV_CMD + QString::number(SID) + DIV_CMD +
        curDatetime.toString("yyyy-MM-ddThh:mm:ss") + DIV_CMD + message + DIV_CMD);
    this->messageGet(QString::number(SID) + DIV_CMD + curDatetime.toString("yyyy-MM-dd hh:mm:ss") + DIV_CMD + message);
    this->ui->plainTextEdit->clear();
}


void groupChatWidget::on_ReloadButton_clicked()
{
    //ui->listWidget->clear();
    emit sendMessageSignal("REQUESTGROUPINFO", QString::number(SID) + DIV_CMD + QString::number(GID) + DIV_CMD);
}

