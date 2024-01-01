#include "chatwidgets.h"
#include "ui_chatwidgets.h"
#include "chatwidget.h"

#include <qdebug.h>

chatWidgets::chatWidgets(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chatWidgets)
{
    ui->setupUi(this);
    ui->tabWidget->clear();
}

chatWidgets::~chatWidgets()
{
    delete ui;
}
void chatWidgets::buildFriendSlot(QString info)
{
    qDebug() << ":" << info;
    chatWidget* ovo = new chatWidget(info, this);
    ui->tabWidget->addTab(ovo, ovo->friendName);
}
void chatWidgets::showChatWidgetSlot()
{
    this->show();
}