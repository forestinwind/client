/********************************************************************************
** Form generated from reading UI file 'groupboxwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPBOXWIDGET_H
#define UI_GROUPBOXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_groupBoxWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *head;
    QVBoxLayout *verticalLayout;
    QLabel *groupNamelabel;
    QLabel *groupSignlabel;

    void setupUi(QWidget *groupBoxWidget)
    {
        if (groupBoxWidget->objectName().isEmpty())
            groupBoxWidget->setObjectName(QString::fromUtf8("groupBoxWidget"));
        groupBoxWidget->resize(300, 100);
        horizontalLayout = new QHBoxLayout(groupBoxWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        head = new QLabel(groupBoxWidget);
        head->setObjectName(QString::fromUtf8("head"));
        head->setMinimumSize(QSize(64, 64));
        head->setMaximumSize(QSize(64, 64));

        horizontalLayout->addWidget(head);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupNamelabel = new QLabel(groupBoxWidget);
        groupNamelabel->setObjectName(QString::fromUtf8("groupNamelabel"));
        QFont font;
        font.setPointSize(16);
        groupNamelabel->setFont(font);

        verticalLayout->addWidget(groupNamelabel);

        groupSignlabel = new QLabel(groupBoxWidget);
        groupSignlabel->setObjectName(QString::fromUtf8("groupSignlabel"));

        verticalLayout->addWidget(groupSignlabel);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(groupBoxWidget);

        QMetaObject::connectSlotsByName(groupBoxWidget);
    } // setupUi

    void retranslateUi(QWidget *groupBoxWidget)
    {
        groupBoxWidget->setWindowTitle(QCoreApplication::translate("groupBoxWidget", "Form", nullptr));
        head->setText(QString());
        groupNamelabel->setText(QCoreApplication::translate("groupBoxWidget", "1", nullptr));
        groupSignlabel->setText(QCoreApplication::translate("groupBoxWidget", "2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupBoxWidget: public Ui_groupBoxWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPBOXWIDGET_H
