#include "Page.h"

Page::Page(QWidget *parent)
    : QMainWindow(parent)
{
    stackedWidget = new QStackedWidget(this);
    loginPage = new LoginPage(this);
    registerPage = new RegisterPage(this);

    stackedWidget->addWidget(loginPage);
    stackedWidget->addWidget(registerPage);

    setCentralWidget(stackedWidget);

    stackedWidget->setCurrentWidget(loginPage);
    loginPage->show();
}
