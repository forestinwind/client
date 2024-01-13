#include <qdatetime.h>

#include <qdebug.h>
#include <qmap.h>

#include "chatwidget.h"
#include "ui_chatwidget.h"
#include "..\shared\shared.h"
#include "chatwidgets.h"

chatWidget::chatWidget(QString info,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chatWidget)
{
    ui->setupUi(this);
    SID = divide(info, DIV_CMD).toInt();
    FID = divide(info, DIV_CMD).toInt();
    friendName = info;

}
chatWidget::chatWidget(qint32 sid,qint32 fid,QString name, QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::chatWidget)
{
    ui->setupUi(this);
    SID = sid;
    FID = fid;
    friendName = name;

}

chatWidget::~chatWidget()
{
    emit deleteChatWidgetSignal(FID);
    qDebug() << "delete ui";
    delete ui;
}
void chatWidget::construct()
{
    emit sendMessageSignal("QUERY", QString::number(SID) + DIV_CMD + QString::number(FID) + DIV_CMD);
}
void chatWidget::chatReflesh(QString init)
{
    qDebug() <<"?" << init;
    //qint32 num = divide(init, DIV_CMD).toInt();
    ui->textBrowser->clear();
    while (init != "")
    {
        QString cur = divide(init, INF_CMD);
        qint32 sit = divide(cur, DIV_CMD).toInt();
        if(sit == 1)
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
    qDebug() << "this:" << this;
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
    qDebug() << "UI:" << this->ui;
    emit sendMessageSignal("SENDCHAT", QString::number(SID) + DIV_CMD + QString::number(FID) + DIV_CMD +
        curDatetime.toString("yyyy-MM-ddThh:mm:ss") + DIV_CMD + readTextEdit() + DIV_CMD);

    this->messageSent(curDatetime.toString("yyyy-MM-ddThh:mm:ss") + DIV_CMD + readTextEdit());
    ui->plainTextEdit->clear();
}


void chatWidget::on_pushButtonReload_clicked()
{
    emit sendMessageSignal("QUERY", QString::number(SID) + DIV_CMD + QString::number(FID) + DIV_CMD);
}

