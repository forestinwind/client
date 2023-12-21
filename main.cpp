#include "mainwindow.h"

#include <QApplication>
#include <qhostaddress.h>
#include <qtcpsocket.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QTcpSocket thisSock;
    thisSock.connectToHost(QHostAddress("localhost"),40004);
    if (thisSock.waitForConnected(5000))w.addBrowser("Connected");
    else w.addBrowser("failed");
    return a.exec();
}
