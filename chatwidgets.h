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
    chatWidget* buildFriend(qint32, qint32, qint32, QString);
    void addTab(chatWidget*);
    ~chatWidgets();
    QMap<qint32, chatWidget*> friends;
private:
    Ui::chatWidgets* ui;
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
