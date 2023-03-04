/********************************************************************************
** Form generated from reading UI file 'RegisterPage.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERPAGE_H
#define UI_REGISTERPAGE_H

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

class Ui_RegisterPage
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *confirmPasswordLineEdit;
    QLineEdit *emailLineEdit;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *horizontalGroupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QPushButton *createUserButton;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *RegisterPage)
    {
        if (RegisterPage->objectName().isEmpty())
            RegisterPage->setObjectName("RegisterPage");
        RegisterPage->resize(727, 499);
        verticalLayout = new QVBoxLayout(RegisterPage);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        titleLabel = new QLabel(RegisterPage);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(20);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        usernameLineEdit = new QLineEdit(RegisterPage);
        usernameLineEdit->setObjectName("usernameLineEdit");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(14);
        usernameLineEdit->setFont(font1);
        usernameLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(usernameLineEdit);

        passwordLineEdit = new QLineEdit(RegisterPage);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setFont(font1);
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        passwordLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(passwordLineEdit);

        confirmPasswordLineEdit = new QLineEdit(RegisterPage);
        confirmPasswordLineEdit->setObjectName("confirmPasswordLineEdit");
        confirmPasswordLineEdit->setFont(font1);
        confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
        confirmPasswordLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(confirmPasswordLineEdit);

        emailLineEdit = new QLineEdit(RegisterPage);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setFont(font1);
        emailLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(emailLineEdit);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalGroupBox = new QGroupBox(RegisterPage);
        horizontalGroupBox->setObjectName("horizontalGroupBox");
        horizontalLayout = new QHBoxLayout(horizontalGroupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        backButton = new QPushButton(horizontalGroupBox);
        backButton->setObjectName("backButton");
        backButton->setEnabled(true);
        backButton->setFont(font1);

        horizontalLayout->addWidget(backButton);

        createUserButton = new QPushButton(horizontalGroupBox);
        createUserButton->setObjectName("createUserButton");
        createUserButton->setFont(font1);

        horizontalLayout->addWidget(createUserButton);


        verticalLayout->addWidget(horizontalGroupBox);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        retranslateUi(RegisterPage);

        QMetaObject::connectSlotsByName(RegisterPage);
    } // setupUi

    void retranslateUi(QWidget *RegisterPage)
    {
        RegisterPage->setWindowTitle(QCoreApplication::translate("RegisterPage", "Register", nullptr));
        titleLabel->setText(QCoreApplication::translate("RegisterPage", "Register", nullptr));
        usernameLineEdit->setStyleSheet(QCoreApplication::translate("RegisterPage", "QLineEdit {\n"
"border: 2px solid #ccc;\n"
"border-radius: 10px;\n"
"padding: 10px;\n"
"}", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("RegisterPage", "Username", nullptr));
        passwordLineEdit->setStyleSheet(QCoreApplication::translate("RegisterPage", "QLineEdit {\n"
"     border: 2px solid #ccc;\n"
"     border-radius: 10px;\n"
"     padding: 10px;\n"
"     }", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("RegisterPage", "Password", nullptr));
        confirmPasswordLineEdit->setStyleSheet(QCoreApplication::translate("RegisterPage", "QLineEdit {\n"
"     border: 2px solid #ccc;\n"
"     border-radius: 10px;\n"
"     padding: 10px;\n"
"     }", nullptr));
        confirmPasswordLineEdit->setPlaceholderText(QCoreApplication::translate("RegisterPage", "Confirm Password", nullptr));
        emailLineEdit->setStyleSheet(QCoreApplication::translate("RegisterPage", "QLineEdit {\n"
"     border: 2px solid #ccc;\n"
"     border-radius: 10px;\n"
"     padding: 10px;\n"
"     }", nullptr));
        emailLineEdit->setPlaceholderText(QCoreApplication::translate("RegisterPage", "Email", nullptr));
        backButton->setStyleSheet(QCoreApplication::translate("RegisterPage", "QPushButton {\n"
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
        backButton->setText(QCoreApplication::translate("RegisterPage", "Back", nullptr));
        createUserButton->setStyleSheet(QCoreApplication::translate("RegisterPage", "QPushButton {\n"
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
        createUserButton->setText(QCoreApplication::translate("RegisterPage", "Create User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterPage: public Ui_RegisterPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERPAGE_H
