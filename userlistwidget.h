#pragma once

#include <QWidget>
#include <qlistwidget.h>
#include <qmap.h>
#include <qvector.h>
#include <qicon.h>
#include <qmouseeventtransition.h>
#include <qmenu.h>

#include "groupboxwidget.h"
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
    void DeleteUser(qint32);
    void DeleteGroup(qint32);

private:
    Ui::userListWidget *ui;
    QMap<QListWidgetItem*, QListWidgetItem*> itemParMap;
    QMap<QListWidgetItem*, bool> itemShowMap;
    QMap<QListWidgetItem*, userBoxWidget*> itemToUserBox;
    QMap<QListWidgetItem*, groupBoxWidget*> itemToGroupBox;
    QMap<qint32, QListWidgetItem*> SIDtoitem;
    QMap<qint32, userBoxWidget*> SIDtobox;
    QMap<qint32, QListWidgetItem*> GIDtoitem;
    QMap<qint32, groupBoxWidget*> GIDtobox;
    QListWidgetItem* youitem;
    QListWidgetItem* frienditem;
    QListWidgetItem* groupitem;

    QListWidgetItem* curItem; //保存最后点击，给menu使用
    QMenu* friendMenu;
    QMenu* yourMenu;
    QMenu* groupMenu;

    void mousePressEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent*);
    void contextMenuEvent(QContextMenuEvent* event);
    void buildFriendFunc(QListWidgetItem*, qint32, qint32);
    void buildGroupFunc(QListWidgetItem*, qint32, qint32);
//    QVector<QListWidgetItem*> itemvec;

public slots:
    void buildFriendSlot(qint32, qint32);
    void buildGroupSlot(qint32, qint32);
    void deletefriendSlot();
    void changeHeadSlot();
    void changeSignSlot();
    void removeSucceedSlot(QString);
    void quitGroupSlot(QString);
    void forwardToGroupSlot(QString, QString);
    void forwardToUserSlot(QString, QString);
signals:
    qint32 sendMessageSignal(QString, QString);
};


