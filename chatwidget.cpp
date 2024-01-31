#include <qdatetime.h>

#include <qdebug.h>
#include <qmap.h>

#include "chatwidget.h"
#include "ui_chatwidget.h"
#include "..\shared\shared.h"
#include "chatwidgets.h"

chatWidget::chatWidget(qint32 sid,qint32 fid, chatWidgets* parent)
    : QWidget(parent)
    , ui(new Ui::chatWidget)
{
    ui->setupUi(this);
    SID = sid;
    FID = fid;
    connect(this, SIGNAL(sendMessageSignal(QString, QString)), parent, SIGNAL(sendMessageSignal(QString, QString)));
    connect(this, SIGNAL(deleteChatWidgetSignal(qint32)), parent, SLOT(deleteChatWidgetSlot(qint32)));
    par = parent;
    emit sendMessageSignal("QUERY", QString::number(SID) + DIV_CMD + QString::number(FID) + DIV_CMD);
    emit sendMessageSignal("REQUESTINFO", QString::number(SID) + DIV_CMD + QString::number(FID) + DIV_CMD);
}

chatWidget::~chatWidget()
{
    emit deleteChatWidgetSignal(FID);
    qDebug() << "delete ui";
    delete ui;
}
void chatWidget::setName(QString name)
{
    friendName = name;
    
    par->setTabText(par->indexOf(this), name);
}
void chatWidget::chatReflesh(QString init)
{
    qDebug() <<"?" << init;
    friendName = divide(init, DIV_CMD);
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
    ui->textBrowser->append("<font color=\"blue\"> YOU:" + toFormat(init) + "</font>");
}

void chatWidget::on_pushButtonSend_clicked()
{
    QDateTime curDatetime = QDateTime::currentDateTime();
    QString message = escape(readTextEdit());
    qDebug() << "UI:" << this->ui;
    emit sendMessageSignal("SENDCHAT", QString::number(SID) + DIV_CMD + QString::number(FID) + DIV_CMD +
        curDatetime.toString("yyyy-MM-ddThh:mm:ss") + DIV_CMD + message + DIV_CMD);

    this->messageSent(curDatetime.toString("yyyy-MM-ddThh:mm:ss") + DIV_CMD + message);
    ui->plainTextEdit->clear();
}


void chatWidget::on_pushButtonReload_clicked()
{
    emit sendMessageSignal("QUERY", QString::number(SID) + DIV_CMD + QString::number(FID) + DIV_CMD);
}

