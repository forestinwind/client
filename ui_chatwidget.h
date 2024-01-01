/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatWidget
{
public:
    QPlainTextEdit *plainTextEdit;
    QTextBrowser *textBrowser;
    QPushButton *pushButtonSend;
    QPushButton *pushButtonReload;

    void setupUi(QWidget *chatWidget)
    {
        if (chatWidget->objectName().isEmpty())
            chatWidget->setObjectName(QString::fromUtf8("chatWidget"));
        chatWidget->resize(445, 349);
        plainTextEdit = new QPlainTextEdit(chatWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 180, 381, 81));
        textBrowser = new QTextBrowser(chatWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 381, 161));
        pushButtonSend = new QPushButton(chatWidget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(339, 267, 51, 21));
        pushButtonReload = new QPushButton(chatWidget);
        pushButtonReload->setObjectName(QString::fromUtf8("pushButtonReload"));
        pushButtonReload->setGeometry(QRect(249, 267, 81, 21));

        retranslateUi(chatWidget);

        QMetaObject::connectSlotsByName(chatWidget);
    } // setupUi

    void retranslateUi(QWidget *chatWidget)
    {
        chatWidget->setWindowTitle(QCoreApplication::translate("chatWidget", "Form", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("chatWidget", "Send", nullptr));
        pushButtonReload->setText(QCoreApplication::translate("chatWidget", "Reload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatWidget: public Ui_chatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
