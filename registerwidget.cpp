﻿#include "registerwidget.h"
#include "ui_registerwidget.h"
#include "..\shared\shared.h"

registerWidget::registerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::registerWidget)
{
    ui->setupUi(this);
    show();
    ui->checkBox->setChecked(true);
}

registerWidget::~registerWidget()
{
    delete ui;
}

void registerWidget::on_pushButton_clicked()
{
    QString pass = ui->passwordLineEdit->text();
    QString check = ui->checkLineEdit->text();
    QString userName = ui->nameLineEdit->text();
    if (pass != check)showERR("密码需一致");
    else if (pass == "")showERR("密码不能为空");
    else emit sendMessageSignal("REGISTER", userName + DIV_CMD + pass);
}
void registerWidget::showERR(QString init)
{
    ui->resLabel->setText(init);
}

void registerWidget::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->checkLineEdit->setEchoMode(QLineEdit::Password);
        ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->checkLineEdit->setEchoMode(QLineEdit::Normal);
        ui->passwordLineEdit->setEchoMode(QLineEdit::Normal);
    }
}

