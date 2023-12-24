#include "mainwindow.h"

#include <QApplication>
#include <qhostaddress.h>
#include <qtcpsocket.h>
#include <qobject.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //thisSock.close();
    return a.exec();
}
