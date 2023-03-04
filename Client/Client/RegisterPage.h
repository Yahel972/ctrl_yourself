#pragma once
#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include "ui_RegisterPage.h"
#include <QWidget>

namespace Ui { class RegisterPage; }

class RegisterPage : public QWidget
{
    Q_OBJECT

public:
    RegisterPage(QWidget *parent = nullptr);
    ~RegisterPage();

private slots:
    void on_createUser_button_clicked();
    void on_back_button_clicked();

private:
    Ui::RegisterPage *ui;
};

#endif
