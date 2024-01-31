#pragma once

#include <QWidget>


namespace Ui {
class chatWidget;
}
class chatWidgets;
class chatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit chatWidget(qint32, qint32, chatWidgets* parent = nullptr);
    void chatReflesh(QString);
    void chatAdd(QString);
    void setName(QString);
    ~chatWidget();
    qint32 FID;
    qint32 SID;
    QString friendName;

private:
    Ui::chatWidget *ui;
    chatWidgets* par;
    QString readTextEdit();
    void messageSent(QString);
    void messageGet(QString);
signals:
    qint32 sendMessageSignal(QString, QString);
    void deleteChatWidgetSignal(qint32);
private slots:
    void on_pushButtonSend_clicked();
    void on_pushButtonReload_clicked();
};

