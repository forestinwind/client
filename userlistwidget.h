#pragma once

#include <QWidget>
#include <qlistwidget.h>
#include <qmap.h>
#include <qvector.h>
#include <qicon.h>
#include <qmouseeventtransition.h>
#include <qmenu.h>

#include "userboxwidget.h"
#include "chatwidgets.h"

namespace Ui {
class userListWidget;
}
//class userBoxWidget;

class userListWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit userListWidget(QWidget *parent = nullptr);
    ~userListWidget();
    chatWidgets *thischatwidget;
    QListWidgetItem* addClass(QString);

private:
    Ui::userListWidget *ui;
    QMap<QListWidgetItem*, QListWidgetItem*> itemParMap;
    QMap<QListWidgetItem*, bool> itemShowMap;
    QMap<QListWidgetItem*, userBoxWidget*> itemToBox;
    QMap<qint32, QListWidgetItem*> IDtoitem;
    QListWidgetItem* ovoitem;

    QListWidgetItem* curItem; //保存最后点击，给menu使用
    QMenu* friendMenu;

    void mousePressEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent*);
    void contextMenuEvent(QContextMenuEvent* event);
//    QVector<QListWidgetItem*> itemvec;

public slots:
    void buildFriendSlot(QString);
    void deletefriendSlot();
    void removeSucceedSlot(QString);
signals:
    qint32 sendMessageSignal(QString);
};


