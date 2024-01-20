#pragma once

#include <QWidget>
#include <qvector.h>
#include <qtabwidget.h>
#include <QMap>

#include "chatwidget.h"



class chatWidgets : public QTabWidget
{
    Q_OBJECT
public:
    explicit chatWidgets(QWidget *parent = nullptr);
    chatWidget* buildFriend(qint32, qint32);
    void buildTab(chatWidget*);
    ~chatWidgets();
    QMap<qint32, chatWidget* > friends;
    void showTab(chatWidget*);
private:
public slots:
    void showChatWidgetSlot();
    void chatRecordSlot(QString);
    void chatAddSlot(QString);
    void deleteChatWidgetSlot(qint32);
    void on_tabWidget_tabCloseRequested(qint32);
signals:
    qint32 sendMessageSignal(QString, QString);
    void tabCloseRequested(qint32);
private slots:
};
