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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatWidgets
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QWidget *chatWidgets)
    {
        if (chatWidgets->objectName().isEmpty())
            chatWidgets->setObjectName(QString::fromUtf8("chatWidgets"));
        chatWidgets->resize(407, 335);
        tabWidget = new QTabWidget(chatWidgets);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 401, 331));
        tabWidget->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(chatWidgets);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(chatWidgets);
    } // setupUi

    void retranslateUi(QWidget *chatWidgets)
    {
        chatWidgets->setWindowTitle(QCoreApplication::translate("chatWidgets", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("chatWidgets", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("chatWidgets", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatWidgets: public Ui_chatWidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGETS_H
