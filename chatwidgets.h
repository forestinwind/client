#pragma once

#include <QWidget>
#include <qvector.h>
#include <qtabwidget.h>
#include <QMap>

#include "chatwidget.h"
namespace Ui {
class chatWidgets;
}

class chatWidgets : public QWidget
{
    Q_OBJECT
public:
    explicit chatWidgets(QWidget *parent = nullptr);
    ~chatWidgets();
private:
    Ui::chatWidgets* ui;
    QMap<qint32, chatWidget*> friends;
public slots:
    void buildFriendSlot(QString);
    void showChatWidgetSlot();
    int sendMessageSlot(QString);
    void chatRecordSlot(QString);
    void chatAddSlot(QString);
signals:
    int sendMessageSignal(QString);
private slots:
    void on_tabWidget_tabCloseRequested(int index);
};
