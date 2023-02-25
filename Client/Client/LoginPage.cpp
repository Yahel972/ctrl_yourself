#include "loginpage.h"
#include "ui_LoginPage.h"
#include <QDebug>

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    // Connect the login button's clicked signal to the on_loginButton_clicked slot
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginPage::on_loginButton_clicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginPage::on_registerButton_clicked);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_loginButton_clicked()
{
    // TODO: find if exist in database

    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    //qDebug() << "Username:" << username << "Password:" << password;
}


void LoginPage::on_registerButton_clicked()
{
    // TODO: open register tab

    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    //qDebug() << "Username:" << username << "Password:" << password;
}
