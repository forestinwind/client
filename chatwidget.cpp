#include "chatwidget.h"
#include "ui_chatwidget.h"
#include "..\shared\shared.h"

chatWidget::chatWidget(QString info,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chatWidget)
{
    ui->setupUi(this);
    friendId = divide(info, DIV_CMD).toInt();
    friendName = info;
}

chatWidget::~chatWidget()
{
    delete ui;
}
