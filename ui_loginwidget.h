/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit_userName;
    QLineEdit *lineEdit_password;
    QLabel *label_userName;
    QLabel *label_2;
    QPushButton *pushButton_login;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(467, 393);
        textBrowser = new QTextBrowser(LoginWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(60, 240, 231, 31));
        lineEdit_userName = new QLineEdit(LoginWidget);
        lineEdit_userName->setObjectName(QString::fromUtf8("lineEdit_userName"));
        lineEdit_userName->setGeometry(QRect(170, 70, 113, 20));
        lineEdit_password = new QLineEdit(LoginWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(170, 100, 113, 20));
        label_userName = new QLabel(LoginWidget);
        label_userName->setObjectName(QString::fromUtf8("label_userName"));
        label_userName->setGeometry(QRect(80, 70, 81, 21));
        label_2 = new QLabel(LoginWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 100, 81, 21));
        pushButton_login = new QPushButton(LoginWidget);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(180, 130, 101, 41));

        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Form", nullptr));
        label_userName->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p>user name:</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p>password:</p></body></html>", nullptr));
        pushButton_login->setText(QCoreApplication::translate("LoginWidget", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
