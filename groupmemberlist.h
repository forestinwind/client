#ifndef GROUPMEMBERLIST_H
#define GROUPMEMBERLIST_H

#include <QWidget>
#include <qlistwidget.h>
#include <qmouseeventtransition.h>
#include <qmenu.h>

#include "memberboxwidget.h"

class groupMemberlist:public QListWidget
{
    Q_OBJECT
public:
    groupMemberlist(QWidget* parent = nullptr);
    ~groupMemberlist();
    void createItem(QString);
    QListWidgetItem* addClass(QString);
    QMap<qint32, QString> IDtoName;
    qint32 SID;
    qint32 GID;
    QMap<QListWidgetItem*, QListWidgetItem*>itemParMap;
    QMap<QListWidgetItem*, bool> itemShowMap;
    QMap<QListWidgetItem*, int> itemToID;
    QMap<int, QListWidgetItem*> IDtoItem;
    QMap<int, memberBoxWidget*> IDtoBox;

private:
    void mousePressEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent*);
    void contextMenuEvent(QContextMenuEvent* event);
    void setPower();
    QMenu* selfMenu;
    QMenu* adminMenu;
    QMenu* guestMenu;
    QMenu* joinMenu;
    QListWidgetItem* hostitem;
    QListWidgetItem* adminitem;
    QListWidgetItem* guestitem;
    QListWidgetItem* joinitem;
    QListWidgetItem* curItem;
    qint32 thisLevel;
private slots:
    void kickMemberSlot();
    void allowJoinSlot();
    void setAdminSlot();
    void cancelAdminSlot();
signals:
    qint32 sendMessageSignal(QString, QString);
};

#endif // GROUPMEMBERLIST_H
