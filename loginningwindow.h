#ifndef LOGINNINGWINDOW_H
#define LOGINNINGWINDOW_H

#include <QWidget>

namespace Ui {
class LoginningWindow;
}

class LoginningWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginningWindow(QWidget *parent = nullptr);
    ~LoginningWindow();

private:
    Ui::LoginningWindow *ui;
};

#endif // LOGINNINGWINDOW_H
