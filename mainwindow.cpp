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

    connect(thisClient, SIGNAL(writeBrowserSignal(QString)), this, SLOT(writeBrowserSlot(QString)));
    connect(loginWidget, SIGNAL(sendMessageSignal(QString, QString)), thisClient, SLOT(sendMessageSlot(QString, QString)));
    connect(friendListWidget, SIGNAL(sendMessageSignal(QString, QString)), thisClient, SLOT(sendMessageSlot(QString, QString)));
    connect(friendListWidget->thischatwidget, SIGNAL(sendMessageSignal(QString, QString)), thisClient, SLOT(sendMessageSlot(QString, QString)));
    connect(thisClient, SIGNAL(closeLoginWidgetSignal()), loginWidget, SLOT(closeLoginWidgetSlot()));
    connect(thisClient, SIGNAL(fleshUserSignal(QString)), friendListWidget, SLOT(fleshUserSlot(QString)));
//    connect(friendWidget, &chatWidgets::sendMessageSignal, thisClient, &client::sendMessageSlot);

    connect(thisClient, SIGNAL(buildFriendSignal(qint32, qint32)), friendListWidget, SLOT(buildFriendSlot(qint32, qint32)));

 //   connect(thisClient, SIGNAL(buildFriendSignal(QString)),friendListWidget->thischatwidget, SLOT(buildFriendSlot(QString)));
    connect(thisClient, SIGNAL(showChatWidgetSignal()), friendListWidget->thischatwidget, SLOT(showChatWidgetSlot()));
    connect(thisClient, SIGNAL(chatRecordSignal(QString)), friendListWidget->thischatwidget, SLOT(chatRecordSlot(QString)));
    connect(thisClient, SIGNAL(chatAddSignal(QString)), friendListWidget->thischatwidget, SLOT(chatAddSlot(QString)));
    connect(thisClient, SIGNAL(removeSucceedSignal(QString)), friendListWidget, SLOT(removeSucceedSlot(QString)));

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

void MainWindow::on_pushButtonAddFriend_clicked()
{
    thisClient->sendMessageSlot("ADDFRIEND", ui->lineEditFriend->text());
}

