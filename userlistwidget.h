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

class userListWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit userListWidget(QWidget *parent = nullptr);
    ~userListWidget();
    chatWidgets *thischatwidget;
    void addClass(QString);

private:
    Ui::userListWidget *ui;
    QMap<QListWidgetItem*, QListWidgetItem*> itemParMap;
    QMap<QListWidgetItem*, bool> itemShowMap;
//    QVector<QListWidgetItem*> itemvec;

public slots:
    void buildFriendSlot(QString);
};


