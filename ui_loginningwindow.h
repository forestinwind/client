/********************************************************************************
** Form generated from reading UI file 'loginningwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINNINGWINDOW_H
#define UI_LOGINNINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginningWindow
{
public:

    void setupUi(QWidget *LoginningWindow)
    {
        if (LoginningWindow->objectName().isEmpty())
            LoginningWindow->setObjectName(QString::fromUtf8("LoginningWindow"));
        LoginningWindow->resize(400, 300);

        retranslateUi(LoginningWindow);

        QMetaObject::connectSlotsByName(LoginningWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginningWindow)
    {
        LoginningWindow->setWindowTitle(QCoreApplication::translate("LoginningWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginningWindow: public Ui_LoginningWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINNINGWINDOW_H
