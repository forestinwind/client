#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->show();
    connect(&thisClient, &client::writeBrowserSignal, this, &MainWindow::writeBrowserSlot);
    connect(&loginWidget, &LoginWidget::sendMessageSignal, &thisClient, &client::sendMessageSlot);
    if(thisClient.begin())
    {
        qDebug("???");
        loginWidget.show();
        loginWidget.raise();
        loginWidget.activateWindow();
        

    }
    //connect(this, SIGNAL(thisClient._writeBrowser(QString)), this, SLOT(this->weiteBrowser(QString)));
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addBrowser(QString init)
{
    ui->textBrowser->setText(init);
}
void MainWindow::writeBrowserSlot(QString init) //´òÓ¡ÔÚtextBrowser
{
    ui->textBrowser->append(init);
}

void MainWindow::sendMessageSlot(QString init)
{
    emit sendMessageSignal(init);
}