/********************************************************************************
** Form generated from reading UI file 'LoginPage.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *usernameLineEdit;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *passwordLineEdit;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *horizontalGroupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *registerButton;
    QPushButton *loginButton;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(800, 500);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        titleLabel = new QLabel(Login);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(20);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        usernameLineEdit = new QLineEdit(Login);
        usernameLineEdit->setObjectName("usernameLineEdit");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(14);
        usernameLineEdit->setFont(font1);
        usernameLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(usernameLineEdit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        passwordLineEdit = new QLineEdit(Login);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setFont(font1);
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        passwordLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(passwordLineEdit);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalGroupBox = new QGroupBox(Login);
        horizontalGroupBox->setObjectName("horizontalGroupBox");
        horizontalLayout = new QHBoxLayout(horizontalGroupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        registerButton = new QPushButton(horizontalGroupBox);
        registerButton->setObjectName("registerButton");
        registerButton->setEnabled(true);
        registerButton->setFont(font1);

        horizontalLayout->addWidget(registerButton);

        loginButton = new QPushButton(horizontalGroupBox);
        loginButton->setObjectName("loginButton");
        loginButton->setFont(font1);

        horizontalLayout->addWidget(loginButton);


        verticalLayout->addWidget(horizontalGroupBox);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("LoginPage", "Login", nullptr));
        titleLabel->setText(QCoreApplication::translate("LoginPage", "Login", nullptr));
        usernameLineEdit->setStyleSheet(QCoreApplication::translate("LoginPage", "QLineEdit {\n"
"border: 2px solid #ccc;\n"
"border-radius: 10px;\n"
"padding: 10px;\n"
"}", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("LoginPage", "Username", nullptr));
        passwordLineEdit->setStyleSheet(QCoreApplication::translate("LoginPage", "QLineEdit {\n"
"     border: 2px solid #ccc;\n"
"     border-radius: 10px;\n"
"     padding: 10px;\n"
"     }", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("LoginPage", "Password", nullptr));
        registerButton->setStyleSheet(QCoreApplication::translate("LoginPage", "QPushButton {\n"
"     background-color: #2ecc71;\n"
"     color: white;\n"
"     border: none;\n"
"     border-radius: 10px;\n"
"     padding: 10px;\n"
"     min-width: 80px;\n"
"     }\n"
"     QPushButton:hover {\n"
"     background-color: #27ae60;\n"
"     }", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginPage", "Register", nullptr));
        loginButton->setStyleSheet(QCoreApplication::translate("LoginPage", "QPushButton {\n"
"     background-color: #2ecc71;\n"
"     color: white;\n"
"     border: none;\n"
"     border-radius: 10px;\n"
"     padding: 10px;\n"
"     min-width: 80px;\n"
"     }\n"
"     QPushButton:hover {\n"
"     background-color: #27ae60;\n"
"     }", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginPage", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
