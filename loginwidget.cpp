#include <qdebug.h>

#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "..\shared\shared.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
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
    this->close();
}

