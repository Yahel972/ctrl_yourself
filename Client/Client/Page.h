#ifndef PAGE_H
#define PAGE_H

#include <QMainWindow>
#include <QStackedWidget>
#include "LoginPage.h"
#include "RegisterPage.h"

class Page : public QMainWindow
{
    Q_OBJECT

public:
    Page(QWidget *parent = nullptr);

private:
    QStackedWidget *stackedWidget;
    LoginPage *loginPage;
    RegisterPage *registerPage;
};

#endif
