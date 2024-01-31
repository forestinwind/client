/********************************************************************************
** Form generated from reading UI file 'groupchatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATWIDGET_H
#define UI_GROUPCHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "groupmemberlist.h"

QT_BEGIN_NAMESPACE

class Ui_groupChatWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ReloadButton;
    QPushButton *SendButton;
    groupMemberlist *listWidget;

    void setupUi(QWidget *groupChatWidget)
    {
        if (groupChatWidget->objectName().isEmpty())
            groupChatWidget->setObjectName(QString::fromUtf8("groupChatWidget"));
        groupChatWidget->resize(538, 468);
        horizontalLayout_2 = new QHBoxLayout(groupChatWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(groupChatWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(textBrowser);

        plainTextEdit = new QPlainTextEdit(groupChatWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ReloadButton = new QPushButton(groupChatWidget);
        ReloadButton->setObjectName(QString::fromUtf8("ReloadButton"));

        horizontalLayout->addWidget(ReloadButton);

        SendButton = new QPushButton(groupChatWidget);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));

        horizontalLayout->addWidget(SendButton);

        horizontalLayout->setStretch(0, 15);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        listWidget = new groupMemberlist(groupChatWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(listWidget);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);

        retranslateUi(groupChatWidget);

        QMetaObject::connectSlotsByName(groupChatWidget);
    } // setupUi

    void retranslateUi(QWidget *groupChatWidget)
    {
        groupChatWidget->setWindowTitle(QCoreApplication::translate("groupChatWidget", "Form", nullptr));
        ReloadButton->setText(QCoreApplication::translate("groupChatWidget", "Reload", nullptr));
        SendButton->setText(QCoreApplication::translate("groupChatWidget", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupChatWidget: public Ui_groupChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATWIDGET_H
