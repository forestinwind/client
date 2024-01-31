#ifndef GROUPBOXWIDGET_H
#define GROUPBOXWIDGET_H

#include <QWidget>

#include "groupchatwidget.h"

namespace Ui {
class groupBoxWidget;
}

class userListWidget;
class groupBoxWidget : public QWidget
{
    Q_OBJECT

public:
    explicit groupBoxWidget(qint32, qint32, QWidget* parent = nullptr);
    ~groupBoxWidget();
    void fleshGroup(QString);
    void cmdFromClient(QString, QString);
    groupChatWidget* thisChatWidget;
    qint32 GID;
    qint32 SID;

private:
    Ui::groupBoxWidget *ui;
    QString groupName;
    QString signStr;
    userListWidget* par;
};

#endif // GROUPBOXWIDGET_H
