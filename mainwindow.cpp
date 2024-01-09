#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <qsize.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->show();
    loginWidget = new LoginWidget();
  //  friendWidget = new chatWidgets();
    thisClient = new client();
    friendListWidget = ui->listWidget;
    qDebug() << &friendListWidget;

    /*QListWidgetItem* item = new QListWidgetItem();
    ui->listWidget->insertItem(0,item);
    //ovo->setSizeIncrement(thissize.width(), 56);
    userBoxWidget* ovo = new userBoxWidget(this);
    ui->listWidget->setItemWidget(item, ovo);
    QSize thissize = ovo->sizeHint();
    item->setSizeHint(QSize(thissize.width(), thissize.height()));*/

    connect(thisClient, &client::writeBrowserSignal, this, &MainWindow::writeBrowserSlot);
    connect(loginWidget, &LoginWidget::sendMessageSignal, thisClient, &client::sendMessageSlot);
    connect(thisClient, &client::closeLoginWidgetSignal, loginWidget, &LoginWidget::closeLoginWidgetSlot);
//    connect(friendWidget, &chatWidgets::sendMessageSignal, thisClient, &client::sendMessageSlot);
    connect(friendListWidget->thischatwidget, &chatWidgets::sendMessageSignal, thisClient, &client::sendMessageSlot);

    connect(thisClient, &client::buildFriendSignal, friendListWidget, &userListWidget::buildFriendSlot);

    connect(thisClient, &client::buildFriendSignal,friendListWidget->thischatwidget, &chatWidgets::buildFriendSlot);
    connect(thisClient, &client::showChatWidgetSignal, friendListWidget->thischatwidget, &chatWidgets::showChatWidgetSlot);
    connect(thisClient, &client::chatRecordSignal, friendListWidget->thischatwidget, &chatWidgets::chatRecordSlot);
    connect(thisClient, &client::chatAddSignal, friendListWidget->thischatwidget, &chatWidgets::chatAddSlot);

 /*   connect(thisClient, &client::buildFriendSignal, friendWidget, &chatWidgets::buildFriendSlot);
    connect(thisClient, &client::showChatWidgetSignal, friendWidget, &chatWidgets::showChatWidgetSlot);
    connect(thisClient, &client::chatRecordSignal, friendWidget, &chatWidgets::chatRecordSlot);
    connect(thisClient, &client::chatAddSignal, friendWidget, &chatWidgets::chatAddSlot);*/

    if(thisClient->begin())
    {
        loginWidget->show();
        //loginWidget.raise();
        //loginWidget.activateWindow();
        

    }
    //connect(this, SIGNAL(thisClient._writeBrowser(QString)), this, SLOT(this->weiteBrowser(QString)));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeBrowserSlot(QString init) // textBrowser
{
    qDebug() << init;
    ui->textBrowser->append(init);
}

void MainWindow::sendMessageSlot(QString init)
{
    emit sendMessageSignal(init);
}




