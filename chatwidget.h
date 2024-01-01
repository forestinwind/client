#pragma once

#include <QWidget>

namespace Ui {
class chatWidget;
}

class chatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit chatWidget(QString info,QWidget *parent = nullptr);
    ~chatWidget();
    int friendId;
    QString friendName;

private:
    Ui::chatWidget *ui;
};

