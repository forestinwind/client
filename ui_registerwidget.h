/********************************************************************************
** Form generated from reading UI file 'registerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *userNameLabel;
    QLineEdit *nameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QLabel *checkLabel;
    QLineEdit *checkLineEdit;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QLabel *resLabel;

    void setupUi(QWidget *registerWidget)
    {
        if (registerWidget->objectName().isEmpty())
            registerWidget->setObjectName(QString::fromUtf8("registerWidget"));
        registerWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(registerWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        userNameLabel = new QLabel(registerWidget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));

        gridLayout->addWidget(userNameLabel, 0, 0, 1, 1);

        nameLineEdit = new QLineEdit(registerWidget);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 0, 1, 1, 1);

        passwordLabel = new QLabel(registerWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        gridLayout->addWidget(passwordLabel, 1, 0, 1, 1);

        passwordLineEdit = new QLineEdit(registerWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));

        gridLayout->addWidget(passwordLineEdit, 1, 1, 1, 1);

        checkLabel = new QLabel(registerWidget);
        checkLabel->setObjectName(QString::fromUtf8("checkLabel"));

        gridLayout->addWidget(checkLabel, 2, 0, 1, 1);

        checkLineEdit = new QLineEdit(registerWidget);
        checkLineEdit->setObjectName(QString::fromUtf8("checkLineEdit"));

        gridLayout->addWidget(checkLineEdit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton = new QPushButton(registerWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        checkBox = new QCheckBox(registerWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        resLabel = new QLabel(registerWidget);
        resLabel->setObjectName(QString::fromUtf8("resLabel"));
        resLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(resLabel);


        retranslateUi(registerWidget);

        QMetaObject::connectSlotsByName(registerWidget);
    } // setupUi

    void retranslateUi(QWidget *registerWidget)
    {
        registerWidget->setWindowTitle(QCoreApplication::translate("registerWidget", "Form", nullptr));
        userNameLabel->setText(QCoreApplication::translate("registerWidget", "username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("registerWidget", "password", nullptr));
        checkLabel->setText(QCoreApplication::translate("registerWidget", "check password", nullptr));
        pushButton->setText(QCoreApplication::translate("registerWidget", "register", nullptr));
        checkBox->setText(QCoreApplication::translate("registerWidget", "hide Password", nullptr));
        resLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class registerWidget: public Ui_registerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H
