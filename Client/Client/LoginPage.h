#pragma once
#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include "ui_LoginPage.h"
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QStackedWidget>

namespace Ui { class LoginPage; }

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

    void set_central_stackedWidget(QStackedWidget* stackedWidget);
    void open_main_window();

private slots:
    void on_login_button_clicked();
    void on_register_button_clicked();

private:
    Ui::LoginPage *ui;

    bool authenticate(QString username, QString password);
};

#endif // LOGINPAGE_H
