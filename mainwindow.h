﻿#pragma once

#include <QMainWindow>
#include <qtcpsocket.h>
#include <qhostaddress.h>

#include "userlistwidget.h"
#include "userboxwidget.h"
#include "chatwidgets.h"
#include "loginwidget.h"
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LoginWidget *loginWidget;
//    chatWidgets *friendWidget;
    client *thisClient; //内含socket
    userListWidget* friendListWidget;
    //QTcpSocket thisSock;
public slots:
    //void readSock();
    void writeBrowserSlot(QString);
signals:
   // void sendMessageSignal(QString);
private slots:
    void on_pushButtonAddFriend_clicked();
    void on_pushButtonAddGroup_clicked();
};
