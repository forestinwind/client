/********************************************************************************
** Form generated from reading UI file 'userlistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLISTWIDGET_H
#define UI_USERLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userListWidget
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *userListWidget)
    {
        if (userListWidget->objectName().isEmpty())
            userListWidget->setObjectName(QString::fromUtf8("userListWidget"));
        userListWidget->resize(353, 220);
        verticalLayout = new QVBoxLayout(userListWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        retranslateUi(userListWidget);

        QMetaObject::connectSlotsByName(userListWidget);
    } // setupUi

    void retranslateUi(QWidget *userListWidget)
    {
        userListWidget->setWindowTitle(QCoreApplication::translate("userListWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userListWidget: public Ui_userListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLISTWIDGET_H
