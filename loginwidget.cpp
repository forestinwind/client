#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <qdebug.h>

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
    int res = sendMessageSignal("LOGIN " + ui->lineEdit_userName->text() + " " + ui->lineEdit_password->text());
    qDebug() << res;
}

