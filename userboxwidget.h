#ifndef USERBOXWIDGET_H
#define USERBOXWIDGET_H

#include <QWidget>
#include <qevent.h>

#include "userlistwidget.h"
#include "chatwidget.h"
#include "chatwidgets.h"

namespace Ui {
class userBoxWidget;
}

class userBoxWidget : public QWidget
{
    Q_OBJECT

public:
    explicit userBoxWidget(QString info, QWidget* parent = nullptr);
    ~userBoxWidget();
    void createChatWidget();
    void mouseDoubleClickEvent(QEvent*);

private:
    Ui::userBoxWidget *ui;
    qint32 friendId;
    qint32 FID;
    qint32 SID;
    QString friendName;
public:
    chatWidget* thisChatWidget;
};

#endif // USERBOXWIDGET_H
