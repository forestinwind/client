#pragma once

#include <QWidget>


namespace Ui {
class chatWidget;
}

class chatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit chatWidget(QString info,QWidget *parent = nullptr);
    explicit chatWidget(qint32, qint32, QString, QWidget* parent = nullptr);
    void construct();
    void chatReflesh(QString);
    void chatAdd(QString);
    ~chatWidget();
    qint32 FID;
    qint32 SID;
    QString friendName;

private:
    Ui::chatWidget *ui;
    QString readTextEdit();
    void messageSent(QString);
    void messageGet(QString);
    QString toFormat(QString);
signals:
    qint32 sendMessageSignal(QString,QString);
    void deleteChatWidgetSignal(qint32);
private slots:
    void on_pushButtonSend_clicked();
    void on_pushButtonReload_clicked();
};

