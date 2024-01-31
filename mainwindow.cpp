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
    connect(thisClient, SIGNAL(logFailCMDSignal(QString)), loginWidget, SLOT(logFailCMDSlot(QString)));


    connect(thisClient, SIGNAL(forwardToGroupSignal(QString, QString)), friendListWidget, SLOT(forwardToGroupSlot(QString,QString)));//转发
    connect(thisClient, SIGNAL(forwardToUserSignal(QString, QString)), friendListWidget, SLOT(forwardToUserSlot(QString, QString)));//转发

    connect(thisClient, SIGNAL(buildFriendSignal(qint32, qint32)), friendListWidget, SLOT(buildFriendSlot(qint32, qint32)));
    connect(thisClient, SIGNAL(buildGroupSignal(qint32, qint32)), friendListWidget, SLOT(buildGroupSlot(qint32, qint32)));

    connect(thisClient, SIGNAL(showChatWidgetSignal()), friendListWidget->thischatwidget, SLOT(showChatWidgetSlot()));
    connect(thisClient, SIGNAL(removeSucceedSignal(QString)), friendListWidget, SLOT(removeSucceedSlot(QString)));
    connect(thisClient, SIGNAL(quitGroupSignal(QString)), friendListWidget, SLOT(quitGroupSlot(QString)));
    

    if(thisClient->begin())
    {
        loginWidget->show();
        //loginWidget.raise();
        //loginWidget.activateWindow();
        

    }
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
    ui->lineEditFriend->clear();
}


void MainWindow::on_pushButtonAddGroup_clicked()
{
    if (ui->lineEditFriend->text().toInt())
    {
        thisClient->sendMessageSlot("ADDGROUP", ui->lineEditFriend->text());
        ui->lineEditFriend->clear();
    }
}

