#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtcpsocket.h>
#include <qhostaddress.h>

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
    QTcpSocket thisSock;
public slots:
    void readSock();
    void writeBrowser(QString);
signals:
    void _writeBrowser(QString);
};
#endif // MAINWINDOW_H
