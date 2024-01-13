#pragma once

#include <QWidget>
#include "registerwidget.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private slots:
    void on_pushButton_login_clicked();
    void on_registerButton_clicked();

public slots:
    void closeLoginWidgetSlot();
signals:
    qint32 sendMessageSignal(QString, QString);
private:
    Ui::LoginWidget *ui;
    registerWidget* regWidget;
};

