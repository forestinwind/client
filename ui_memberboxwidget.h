/********************************************************************************
** Form generated from reading UI file 'memberboxwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMBERBOXWIDGET_H
#define UI_MEMBERBOXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_memberBoxWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *head;
    QVBoxLayout *verticalLayout;
    QLabel *namelabel;
    QLabel *signlabel;

    void setupUi(QWidget *memberBoxWidget)
    {
        if (memberBoxWidget->objectName().isEmpty())
            memberBoxWidget->setObjectName(QString::fromUtf8("memberBoxWidget"));
        memberBoxWidget->resize(200, 76);
        horizontalLayout = new QHBoxLayout(memberBoxWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        head = new QLabel(memberBoxWidget);
        head->setObjectName(QString::fromUtf8("head"));
        head->setMinimumSize(QSize(64, 64));
        head->setMaximumSize(QSize(64, 64));

        horizontalLayout->addWidget(head);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        namelabel = new QLabel(memberBoxWidget);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        QFont font;
        font.setPointSize(16);
        namelabel->setFont(font);

        verticalLayout->addWidget(namelabel);

        signlabel = new QLabel(memberBoxWidget);
        signlabel->setObjectName(QString::fromUtf8("signlabel"));

        verticalLayout->addWidget(signlabel);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(memberBoxWidget);

        QMetaObject::connectSlotsByName(memberBoxWidget);
    } // setupUi

    void retranslateUi(QWidget *memberBoxWidget)
    {
        memberBoxWidget->setWindowTitle(QCoreApplication::translate("memberBoxWidget", "Form", nullptr));
        head->setText(QString());
        namelabel->setText(QCoreApplication::translate("memberBoxWidget", "\346\235\216\345\250\201", nullptr));
        signlabel->setText(QCoreApplication::translate("memberBoxWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class memberBoxWidget: public Ui_memberBoxWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMBERBOXWIDGET_H
