#ifndef GROUPCHATWIDGET_H
#define GROUPCHATWIDGET_H

#include <QWidget>

namespace Ui {
class groupChatWidget;
}

class chatWidgets;
class groupChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit groupChatWidget(qint32, qint32, chatWidgets* parent = nullptr);
    ~groupChatWidget();
    void fleshMember(QString);
    void chatReflesh(QString);
    void setName(QString);
    void messageGet(QString);
    void memberKick(QString);

    qint32 SID;
    qint32 GID;
    QString groupName;

private:
    Ui::groupChatWidget *ui;
    chatWidgets* par;
signals:
    void deleteGroupWidgetSignal(qint32);
    qint32 sendMessageSignal(QString, QString);
private slots:
    void on_SendButton_clicked();
    void on_ReloadButton_clicked();
};

#endif // GROUPCHATWIDGET_H
