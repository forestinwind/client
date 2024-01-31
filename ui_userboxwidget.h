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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userBoxWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *head;
    QVBoxLayout *verticalLayout;
    QLabel *userNamelabel;
    QLabel *selfSignlabel;

    void setupUi(QWidget *userBoxWidget)
    {
        if (userBoxWidget->objectName().isEmpty())
            userBoxWidget->setObjectName(QString::fromUtf8("userBoxWidget"));
        userBoxWidget->resize(300, 100);
        horizontalLayout = new QHBoxLayout(userBoxWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        head = new QLabel(userBoxWidget);
        head->setObjectName(QString::fromUtf8("head"));
        head->setMinimumSize(QSize(64, 64));
        head->setMaximumSize(QSize(64, 64));
        head->setStyleSheet(QString::fromUtf8(""));
        head->setPixmap(QPixmap(QString::fromUtf8(":/shared/icon/ranger.jpg")));
        head->setScaledContents(false);

        horizontalLayout->addWidget(head);

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


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(userBoxWidget);

        QMetaObject::connectSlotsByName(userBoxWidget);
    } // setupUi

    void retranslateUi(QWidget *userBoxWidget)
    {
        userBoxWidget->setWindowTitle(QCoreApplication::translate("userBoxWidget", "Form", nullptr));
#if QT_CONFIG(whatsthis)
        head->setWhatsThis(QCoreApplication::translate("userBoxWidget", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        head->setText(QString());
        userNamelabel->setText(QCoreApplication::translate("userBoxWidget", "\346\235\216\345\250\201", nullptr));
        selfSignlabel->setText(QCoreApplication::translate("userBoxWidget", "\346\210\221\351\235\236\345\270\270\345\274\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userBoxWidget: public Ui_userBoxWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERBOXWIDGET_H
