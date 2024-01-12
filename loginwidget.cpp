#include <qdebug.h>

#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "..\shared\shared.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    regWidget = nullptr;
}

LoginWidget::~LoginWidget()
{
    delete ui;
}
void LoginWidget::on_pushButton_login_clicked()
{
    //emit sendMessageSignal("LOGIN admin " + ui->lineEdit_password->text() + "\r\n");
    qint32 res = emit
        sendMessageSignal("LOGIN" + DIV_CMD + ui->lineEdit_userName->text() + DIV_CMD + ui->lineEdit_password->text());
    qDebug() << res;
}
void LoginWidget::closeLoginWidgetSlot()
{
    if (regWidget != nullptr)delete regWidget;
    delete this;
}


void LoginWidget::on_registerButton_clicked()
{
    regWidget = new registerWidget();
    connect(regWidget, &registerWidget::sendMessageSignal, this, &LoginWidget::sendMessageSignal);
}

