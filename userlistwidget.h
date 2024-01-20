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
    QMap<qint32, userBoxWidget*> IDtobox;
    QListWidgetItem* youitem;
    QListWidgetItem* frienditem;

    QListWidgetItem* curItem; //保存最后点击，给menu使用
    QMenu* friendMenu;
    QMenu* yourMenu;

    void mousePressEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent*);
    void contextMenuEvent(QContextMenuEvent* event);
    void buildFriendFunc(QListWidgetItem*, qint32, qint32);
//    QVector<QListWidgetItem*> itemvec;

public slots:
    void buildFriendSlot(qint32, qint32);
    void deletefriendSlot();
    void changeHeadSlot();
    void changeSignSlot();
    void removeSucceedSlot(QString);
    void fleshUserSlot(QString);
signals:
    qint32 sendMessageSignal(QString, QString);
};


