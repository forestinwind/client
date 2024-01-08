/********************************************************************************
** Form generated from reading UI file 'userboxwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERBOXWIDGET_H
#define UI_USERBOXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userBoxWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *userNamelabel;
    QLabel *selfSignlabel;

    void setupUi(QWidget *userBoxWidget)
    {
        if (userBoxWidget->objectName().isEmpty())
            userBoxWidget->setObjectName(QString::fromUtf8("userBoxWidget"));
        userBoxWidget->resize(475, 229);
        gridLayout = new QGridLayout(userBoxWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        userNamelabel = new QLabel(userBoxWidget);
        userNamelabel->setObjectName(QString::fromUtf8("userNamelabel"));
        QFont font;
        font.setPointSize(16);
        userNamelabel->setFont(font);

        verticalLayout->addWidget(userNamelabel);

        selfSignlabel = new QLabel(userBoxWidget);
        selfSignlabel->setObjectName(QString::fromUtf8("selfSignlabel"));

        verticalLayout->addWidget(selfSignlabel);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(userBoxWidget);

        QMetaObject::connectSlotsByName(userBoxWidget);
    } // setupUi

    void retranslateUi(QWidget *userBoxWidget)
    {
        userBoxWidget->setWindowTitle(QCoreApplication::translate("userBoxWidget", "Form", nullptr));
        userNamelabel->setText(QCoreApplication::translate("userBoxWidget", "\346\235\216\345\250\201", nullptr));
        selfSignlabel->setText(QCoreApplication::translate("userBoxWidget", "\346\210\221\351\235\236\345\270\270\345\274\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userBoxWidget: public Ui_userBoxWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERBOXWIDGET_H
