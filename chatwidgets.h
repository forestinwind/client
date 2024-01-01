#pragma once

#include <QWidget>
#include <qvector.h>
#include <qtabwidget.h>

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
public slots:
    void buildFriendSlot(QString);
    void showChatWidgetSlot();
};
