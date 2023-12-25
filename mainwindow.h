#pragma once

#include <QMainWindow>
#include <qtcpsocket.h>
#include <qhostaddress.h>

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
    void addBrowser(QString);
private:
    Ui::MainWindow *ui;
    LoginWidget loginWidget;
    client thisClient; //�ں�socket
    //QTcpSocket thisSock;
public slots:
    //void readSock();
    void writeBrowserSlot(QString);
    void sendMessageSlot(QString);
signals:
    void sendMessageSignal(QString);
};
