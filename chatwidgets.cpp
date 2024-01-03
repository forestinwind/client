#include "chatwidgets.h"
#include "ui_chatwidgets.h"
#include "chatwidget.h"
#include "..\shared\shared.h"

#include <qdebug.h>

chatWidgets::chatWidgets(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chatWidgets)
{
    ui->setupUi(this);
}

chatWidgets::~chatWidgets()
{
    delete ui;
}
void chatWidgets::buildFriendSlot(QString info)
{
    qDebug() << ":" << info;
    chatWidget* thisWidget = new chatWidget(info, this);
    connect(thisWidget, &chatWidget::sendMessageSignal, this, &chatWidgets::sendMessageSlot);
    friends[thisWidget->FID] = thisWidget;
    thisWidget->construct();
    ui->tabWidget->addTab(thisWidget, thisWidget->friendName);
}
void chatWidgets::showChatWidgetSlot()
{
    this->show();
}

qint32 chatWidgets::sendMessageSlot(QString init)
{
    return emit sendMessageSignal(init);
}
void chatWidgets::chatRecordSlot(QString init)
{
    qDebug() << "s:" << init;
    chatWidget* thisWidget = friends[divide(init, DIV_CMD).toInt()];
    qDebug() << "s:" << init;
    thisWidget->chatReflesh(init);
}
void chatWidgets::chatAddSlot(QString init)
{
    chatWidget* thisWidget = friends[divide(init, DIV_CMD).toInt()];
    thisWidget->chatAdd(init);
}
void chatWidgets::on_tabWidget_tabCloseRequested(int index)
{
    chatWidget *curWidget = dynamic_cast<chatWidget*>(ui->tabWidget->widget(index));
    friends.remove(curWidget->FID);;
    ui->tabWidget->removeTab(index);
}

