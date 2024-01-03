#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->show();
    loginWidget = new LoginWidget();
    friendWidget = new chatWidgets();
    thisClient = new client();

    connect(thisClient, &client::writeBrowserSignal, this, &MainWindow::writeBrowserSlot);
    connect(loginWidget, &LoginWidget::sendMessageSignal, thisClient, &client::sendMessageSlot);
    connect(thisClient, &client::buildFriendSignal, friendWidget, &chatWidgets::buildFriendSlot);
    connect(thisClient, &client::showChatWidgetSignal, friendWidget, &chatWidgets::showChatWidgetSlot);
    connect(friendWidget, &chatWidgets::sendMessageSignal, thisClient, &client::sendMessageSlot);
    connect(thisClient, &client::chatRecordSignal, friendWidget, &chatWidgets::chatRecordSlot);
    connect(thisClient, &client::chatAddSignal, friendWidget, &chatWidgets::chatAddSlot);

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

void MainWindow::writeBrowserSlot(QString init) //´òÓ¡ÔÚtextBrowser
{
    qDebug() << init;
    ui->textBrowser->append(init);
}

void MainWindow::sendMessageSlot(QString init)
{
    emit sendMessageSignal(init);
}