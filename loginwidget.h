#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

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
signals:
    void sendMessageSignal(QString);
private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H