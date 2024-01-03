/********************************************************************************
** Form generated from reading UI file 'chatwidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGETS_H
#define UI_CHATWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatWidgets
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;

    void setupUi(QWidget *chatWidgets)
    {
        if (chatWidgets->objectName().isEmpty())
            chatWidgets->setObjectName(QString::fromUtf8("chatWidgets"));
        chatWidgets->resize(601, 479);
        gridLayout = new QGridLayout(chatWidgets);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(chatWidgets);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabsClosable(true);

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(chatWidgets);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(chatWidgets);
    } // setupUi

    void retranslateUi(QWidget *chatWidgets)
    {
        chatWidgets->setWindowTitle(QCoreApplication::translate("chatWidgets", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatWidgets: public Ui_chatWidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGETS_H
