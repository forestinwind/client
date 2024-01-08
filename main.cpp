#include "mainwindow.h"

#include <QApplication>
#include <qhostaddress.h>
#include <qtcpsocket.h>
#include <qobject.h>
#include <qtextcodec.h>
#include <qdebug.h>
int main(int argc, char *argv[])
{
    QTextCodec* code = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(code);

    QApplication a(argc, argv);
    MainWindow w;


    //thisSock.close();
    return a.exec();
}
