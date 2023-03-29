/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemoteControlPage
{
public:
    QWidget *centralwidget;
    QLabel *friendsListLabel;
    QListWidget *friendsList;
    QLabel *onlineFriendsLabel;
    QLabel *addFriendLabel;
    QLineEdit *addFriendLine;
    QListWidget *onlineFriendsList;
    QPushButton *controlRadioButton;
    QPushButton *beControlledRadioButton;
    QPushButton *startButton;

    void setupUi(QMainWindow *RemoteControlPage)
    {
        if (RemoteControlPage->objectName().isEmpty())
            RemoteControlPage->setObjectName("RemoteControlPage");
        RemoteControlPage->resize(727, 499);
        centralwidget = new QWidget(RemoteControlPage);
        centralwidget->setObjectName("centralwidget");
        friendsListLabel = new QLabel(centralwidget);
        friendsListLabel->setObjectName("friendsListLabel");
        friendsListLabel->setGeometry(QRect(20, 20, 181, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(10);
        friendsListLabel->setFont(font);
        friendsList = new QListWidget(centralwidget);
        friendsList->setObjectName("friendsList");
        friendsList->setGeometry(QRect(20, 50, 241, 311));
        friendsList->setFont(font);
        onlineFriendsLabel = new QLabel(centralwidget);
        onlineFriendsLabel->setObjectName("onlineFriendsLabel");
        onlineFriendsLabel->setGeometry(QRect(300, 20, 111, 16));
        onlineFriendsLabel->setFont(font);
        addFriendLabel = new QLabel(centralwidget);
        addFriendLabel->setObjectName("addFriendLabel");
        addFriendLabel->setGeometry(QRect(570, 20, 131, 16));
        addFriendLabel->setFont(font);
        addFriendLine = new QLineEdit(centralwidget);
        addFriendLine->setObjectName("addFriendLine");
        addFriendLine->setGeometry(QRect(570, 50, 221, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(12);
        addFriendLine->setFont(font1);
        onlineFriendsList = new QListWidget(centralwidget);
        onlineFriendsList->setObjectName("onlineFriendsList");
        onlineFriendsList->setGeometry(QRect(290, 50, 231, 311));
        onlineFriendsList->setFont(font1);
        onlineFriendsList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        onlineFriendsList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        onlineFriendsList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        onlineFriendsList->setAutoScroll(true);
        onlineFriendsList->setTabKeyNavigation(false);
        onlineFriendsList->setProperty("showDropIndicator", QVariant(false));
        onlineFriendsList->setDragDropMode(QAbstractItemView::NoDragDrop);
        onlineFriendsList->setIconSize(QSize(40, 40));
        onlineFriendsList->setTextElideMode(Qt::ElideNone);
        onlineFriendsList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        onlineFriendsList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        onlineFriendsList->setMovement(QListView::Static);
        onlineFriendsList->setFlow(QListView::TopToBottom);
        onlineFriendsList->setResizeMode(QListView::Adjust);
        onlineFriendsList->setLayoutMode(QListView::Batched);
        onlineFriendsList->setViewMode(QListView::IconMode);
        onlineFriendsList->setUniformItemSizes(false);
        onlineFriendsList->setWordWrap(false);
        controlRadioButton = new QPushButton(centralwidget);
        controlRadioButton->setObjectName("controlRadioButton");
        controlRadioButton->setGeometry(QRect(290, 360, 100, 30));
        beControlledRadioButton = new QPushButton(centralwidget);
        beControlledRadioButton->setObjectName("beControlledRadioButton");
        beControlledRadioButton->setGeometry(QRect(410, 360, 100, 30));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(290, 400, 221, 30));
        RemoteControlPage->setCentralWidget(centralwidget);

        retranslateUi(RemoteControlPage);

        QMetaObject::connectSlotsByName(RemoteControlPage);
    } // setupUi

    void retranslateUi(QMainWindow *RemoteControlPage)
    {
        RemoteControlPage->setWindowTitle(QCoreApplication::translate("RemoteControlPage", "Remote Control Page", nullptr));
        friendsListLabel->setText(QCoreApplication::translate("RemoteControlPage", "Friends List:", nullptr));
        onlineFriendsLabel->setText(QCoreApplication::translate("RemoteControlPage", "Online Friends:", nullptr));
        addFriendLabel->setText(QCoreApplication::translate("RemoteControlPage", "Add a New Friend:", nullptr));
        addFriendLine->setPlaceholderText(QCoreApplication::translate("RemoteControlPage", "Add friend by email or username", nullptr));
        controlRadioButton->setText(QCoreApplication::translate("RemoteControlPage", "Control", nullptr));
        beControlledRadioButton->setText(QCoreApplication::translate("RemoteControlPage", "Be Controlled", nullptr));
        startButton->setText(QCoreApplication::translate("RemoteControlPage", "Start Remote Control Conversation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoteControlPage: public Ui_RemoteControlPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
