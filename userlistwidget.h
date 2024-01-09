#pragma once

#include <QWidget>
#include <qlistwidget.h>
#include <qmap.h>
#include <qvector.h>
#include <qicon.h>
#include <qevent.h>
#include <qmouseeventtransition.h>

#include "userboxwidget.h"
#include "chatwidgets.h"

namespace Ui {
class userListWidget;
}
class userBoxWidget;

class userListWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit userListWidget(QWidget *parent = nullptr);
    ~userListWidget();
    chatWidgets *thischatwidget;
    QListWidgetItem* addClass(QString);
    void mousePressEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent*);

private:
    Ui::userListWidget *ui;
    QMap<QListWidgetItem*, QListWidgetItem*> itemParMap;
    QMap<QListWidgetItem*, bool> itemShowMap;
    QMap<QListWidgetItem*, userBoxWidget*> itemToBox;
    QListWidgetItem* ovoitem;
//    QVector<QListWidgetItem*> itemvec;

public slots:
    void buildFriendSlot(QString);
};


