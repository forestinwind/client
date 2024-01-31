#pragma once

#include <QWidget>
#include <qvector.h>
#include <qtabwidget.h>
#include <QMap>

#include "chatwidget.h"
#include "groupchatwidget.h"


class chatWidgets : public QTabWidget
{
    Q_OBJECT
public:
    explicit chatWidgets(QWidget *parent = nullptr);
    chatWidget* buildFriend(qint32, qint32);
    groupChatWidget* buildGroup(qint32, qint32);
    void buildTab(chatWidget*);
    void buildTab(groupChatWidget*);
    ~chatWidgets();
    QMap<qint32, chatWidget* > friends;
    QMap<qint32, groupChatWidget* > groups;
    void showTab(chatWidget*);
    void showTab(groupChatWidget*);
private:
public slots:
    void showChatWidgetSlot();
    void deleteChatWidgetSlot(qint32);
    void deleteGroupWidgetSlot(qint32);
    void on_tabWidget_tabCloseRequested(qint32);
signals:
    qint32 sendMessageSignal(QString, QString);
    void tabCloseRequested(qint32);
private slots:
};
