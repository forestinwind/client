#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

#define IPLOC "192.168.1.103"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(thisClient._writeBrowser(QString)), this, SLOT(this->weiteBrowser(QString)));
    connect(&thisSock,&QTcpSocket::readyRead, this, &MainWindow::readSock);
    thisSock.connectToHost(QHostAddress(IPLOC), 40004);
    thisSock.write("michael");
    if (thisSock.waitForConnected(5000))emit writeBrowser("Connected");
    else {
        emit writeBrowser("failed");
    }
    qDebug("init1");
}

void MainWindow::readSock()
{
    qDebug() << "init5" << endl;
    QByteArray buffer;
    buffer = thisSock.readAll();
    if (!buffer.isEmpty())
    {
        QString str = tr(buffer);
        qDebug()<<str<<endl;
        writeBrowser(str);
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addBrowser(QString init)
{
    ui->textBrowser->setText(init);
}
void MainWindow::writeBrowser(QString init)
{
    ui->textBrowser->append(init);
}

