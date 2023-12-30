#include "loginningwindow.h"
#include "ui_loginningwindow.h"

LoginningWindow::LoginningWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginningWindow)
{
    ui->setupUi(this);
}

LoginningWindow::~LoginningWindow()
{
    delete ui;
}
