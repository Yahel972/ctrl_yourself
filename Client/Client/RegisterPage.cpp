#include "RegisterPage.h"
#include "Global.h"

RegisterPage::RegisterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterPage)
{
    ui->setupUi(this);

    connect(ui->backButton, &QPushButton::clicked, this, &RegisterPage::on_back_button_clicked);
    connect(ui->createUserButton, &QPushButton::clicked, this, &RegisterPage::on_createUser_button_clicked);
}


RegisterPage::~RegisterPage()
{
    delete ui;
}


void RegisterPage::on_back_button_clicked()
{
    Global::getStackedWidget()->setCurrentWidget(Global::getStackedWidget()->widget(0));
}


void RegisterPage::on_createUser_button_clicked()
{
    // TODO: check database and create user if possible
    // check also the datas given (such as using regex to find email patterns)
}
