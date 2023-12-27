#include "loginwidget.h"
#include "ui_loginwidget.h"

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
    emit sendMessageSignal("LOGIN " + ui->lineEdit_userName->text() + " " + ui->lineEdit_password->text() + "\r\n");
}

