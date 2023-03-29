/********************************************************************************
** Form generated from reading UI file 'MainPage.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QWidget *centralwidget;
    QLabel *friendsListLabel;
    QListWidget *friendsList;
    QLabel *onlineFriendsLabel;
    QListWidget *onlineFriendsList;
    QLabel *addFriendLabel;
    QLineEdit *addFriendLine;
    QPushButton *addFriendButton;
    QLabel *selectedFriendLabel;
    QLineEdit *selectedFriendLine;
    QPushButton *connectButton;
    QLabel *statusLabel;

    void setupUi(QWidget *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName("MainPage");
        MainPage->resize(800, 500);
        centralwidget = new QWidget(MainPage);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 811, 450));
        friendsListLabel = new QLabel(centralwidget);
        friendsListLabel->setObjectName("friendsListLabel");
        friendsListLabel->setGeometry(QRect(20, 20, 121, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(12);
        friendsListLabel->setFont(font);
        friendsList = new QListWidget(centralwidget);
        friendsList->setObjectName("friendsList");
        friendsList->setGeometry(QRect(20, 50, 241, 311));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(10);
        friendsList->setFont(font1);
        onlineFriendsLabel = new QLabel(centralwidget);
        onlineFriendsLabel->setObjectName("onlineFriendsLabel");
        onlineFriendsLabel->setGeometry(QRect(300, 20, 131, 21));
        onlineFriendsLabel->setFont(font);
        onlineFriendsList = new QListWidget(centralwidget);
        onlineFriendsList->setObjectName("onlineFriendsList");
        onlineFriendsList->setGeometry(QRect(300, 50, 241, 311));
        addFriendLabel = new QLabel(centralwidget);
        addFriendLabel->setObjectName("addFriendLabel");
        addFriendLabel->setGeometry(QRect(570, 20, 161, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        addFriendLabel->setFont(font2);
        addFriendLine = new QLineEdit(centralwidget);
        addFriendLine->setObjectName("addFriendLine");
        addFriendLine->setGeometry(QRect(570, 50, 221, 30));
        addFriendButton = new QPushButton(centralwidget);
        addFriendButton->setObjectName("addFriendButton");
        addFriendButton->setGeometry(QRect(800, 50, 101, 28));
        selectedFriendLabel = new QLabel(centralwidget);
        selectedFriendLabel->setObjectName("selectedFriendLabel");
        selectedFriendLabel->setGeometry(QRect(570, 120, 121, 16));
        selectedFriendLabel->setFont(font1);
        selectedFriendLine = new QLineEdit(centralwidget);
        selectedFriendLine->setObjectName("selectedFriendLine");
        selectedFriendLine->setGeometry(QRect(570, 150, 221, 30));
        selectedFriendLine->setFont(font1);
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(570, 210, 221, 30));
        connectButton->setFont(font1);
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(340, 400, 111, 16));
        statusLabel->setFont(font1);

        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QWidget *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "Remote Control Page", nullptr));
        friendsListLabel->setText(QCoreApplication::translate("MainPage", "Friends List:", nullptr));
        friendsList->setStyleSheet(QCoreApplication::translate("MainPage", "\n"
"         QListWidget {\n"
"            background-color: #FFFFFF;\n"
"            border: 1px solid #B1B1B1;\n"
"            border-radius: 4px;\n"
"            font-family: Segoe UI;\n"
"            font-size: 10pt;\n"
"            padding: 8px;\n"
"         }\n"
"         QListWidget::item {\n"
"            color: #565656;\n"
"            padding: 4px;\n"
"         }\n"
"         QListWidget::item:selected {\n"
"            background-color: #F1F1F1;\n"
"         }\n"
"     ", nullptr));
        onlineFriendsLabel->setText(QCoreApplication::translate("MainPage", "Online Friends:", nullptr));
        onlineFriendsList->setStyleSheet(QCoreApplication::translate("MainPage", "\n"
"            QListWidget {\n"
"                border: none;\n"
"                background-color: #FFF;\n"
"                color: #333;\n"
"                font-size: 16px;\n"
"            }\n"
"            QListWidget::item {\n"
"                border-bottom: 1px solid #DDD;\n"
"                padding: 10px;\n"
"            }\n"
"            QListWidget::item:selected {\n"
"                background-color: #EEE;\n"
"            }\n"
"        ", nullptr));
        addFriendLabel->setStyleSheet(QCoreApplication::translate("MainPage", "\n"
"            QLabel {\n"
"                color: #333;\n"
"                font-size: 18px;\n"
"            }\n"
"        ", nullptr));
        addFriendLabel->setText(QCoreApplication::translate("MainPage", "Add a New Friend:", nullptr));
        addFriendLine->setStyleSheet(QCoreApplication::translate("MainPage", "\n"
"            QLineEdit {\n"
"                border: 2px solid #CCC;\n"
"                border-radius: 15px;\n"
"                background-color: #FFF;\n"
"                font-size: 16px;\n"
"                padding: 5px 10px;\n"
"                selection-background-color: #EEE;\n"
"            }\n"
"            QLineEdit:focus {\n"
"                border-color: #3CA4FF;\n"
"            }\n"
"        ", nullptr));
        addFriendButton->setStyleSheet(QCoreApplication::translate("MainPage", "\n"
"   QPushButton {\n"
"    border: 2px solid #3CA4FF;\n"
"    border-radius: 15px;\n"
"    background-color: #3CA4FF;\n"
"    color: #FFFFFF;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 5px 20px;\n"
"   }\n"
"   QPushButton:hover {\n"
"    background-color: #FFFFFF;\n"
"    color: #3CA4FF;\n"
"   }\n"
"  ", nullptr));
        addFriendButton->setText(QCoreApplication::translate("MainPage", "Add", nullptr));
        selectedFriendLabel->setText(QCoreApplication::translate("MainPage", "Selected Friend:", nullptr));
        selectedFriendLine->setPlaceholderText(QCoreApplication::translate("MainPage", "Select a friend from the list", nullptr));
        connectButton->setText(QCoreApplication::translate("MainPage", "Connect", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainPage", "Disconnected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
