#include "chatwidget.h"
#include "ui_chatwidget.h"
#include "..\shared\shared.h"
#include <qdatetime.h>

#include <qdebug.h>

chatWidget::chatWidget(QString info,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chatWidget)
{
    ui->setupUi(this);
    SID = divide(info, DIV_CMD).toInt();
    FID = divide(info, DIV_CMD).toInt();
    friendId = divide(info, DIV_CMD).toInt();
    friendName = info;

}
chatWidget::chatWidget(qint32 sid,qint32 fid,qint32 friendid,QString name, QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::chatWidget)
{
    ui->setupUi(this);
    SID = sid;
    FID = fid;
    friendId = friendid;
    friendName = name;

}

chatWidget::~chatWidget()
{
    delete ui;
}
void chatWidget::construct()
{
    emit sendMessageSignal("QUERY" + DIV_CMD + QString::number(FID) + DIV_CMD + QString::number(SID));
}
void chatWidget::chatReflesh(QString init)
{
    qint32 num = divide(init, DIV_CMD).toInt();
    ui->textBrowser->clear();
    while (init != "")
    {
        QString cur = divide(init, INF_CMD);
        qint32 sendId = divide(cur, DIV_CMD).toInt();
        if(sendId == FID)
        {
            messageGet(cur);
        }
        else
        {
            messageSent(cur);
        }
    }
}
void chatWidget::chatAdd(QString init)
{
    messageGet(init);
}
QString chatWidget::readTextEdit()
{
    return ui->plainTextEdit->toPlainText();
}
void chatWidget::messageGet(QString init)
{
    ui->textBrowser->append("<font color=\"green\">" + friendName + ":" + toFormat(init) + "</font>");
}
void chatWidget::messageSent(QString init)
{
    ui->textBrowser->append("<font \color=\"blue\"> YOU:" + toFormat(init) + "</font>");
}
QString chatWidget::toFormat(QString init)
{
    QString time = divide(init, DIV_CMD);
    QString day = divide(time, "T");
    QString tem = divide(time, ".");
    if (tem != "")time = tem;
    return "(" + day + " " + time + "):<br>" + init;
}
void chatWidget::on_pushButtonSend_clicked()
{
    QDateTime curDatetime = QDateTime::currentDateTime();
    emit sendMessageSignal("SENDCHAT" + DIV_CMD + QString::number(friendId) + DIV_CMD + 
        QString::number(FID) + DIV_CMD + QString::number(SID) + DIV_CMD +
                curDatetime.toString("yyyy-MM-ddThh:mm:ss") + DIV_CMD + readTextEdit());
    messageSent(curDatetime.toString("yyyy-MM-ddThh:mm:ss") + DIV_CMD + readTextEdit());
    ui->plainTextEdit->clear();
}


void chatWidget::on_pushButtonReload_clicked()
{
    emit sendMessageSignal("QUERY" + DIV_CMD + QString::number(FID) + DIV_CMD + QString::number(SID));
}

