#include "LoginPage.h"
#include "RegisterPage.h"
#include "Global.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginPage::on_login_button_clicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginPage::on_register_button_clicked);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::set_central_stackedWidget(QStackedWidget* stackedWidget)
{
    // Create a new QVBoxLayout and set the stacked widget as its only item
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);

    // Set the layout as the central layout of the parent widget
    this->setLayout(layout);
}


void LoginPage::on_login_button_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (authenticate(username, password)) {
        // TODO: log-in
        QMessageBox::question(this, "Welcome", "Logged in Successfully!", QMessageBox::Ok);
    } else {
        QMessageBox::question(this, "Error", "Invalid username / password given", QMessageBox::Cancel);
        // Show an error message to the user
    }
}

bool LoginPage::authenticate(QString username, QString password)
{
    // TODO: Implement the authentication logic here (db)
    // For now, just return true if the username is "admin" and the password is "password"
    return (username == "admin" && password == "password");
}


void LoginPage::on_register_button_clicked()
{
    Global::getStackedWidget()->setCurrentWidget(Global::getStackedWidget()->widget(1));
}
