#include "Global.h"
#include "LoginPage.h"
#include "RegisterPage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *centralWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    Global::getStackedWidget()->addWidget(new LoginPage);
    Global::getStackedWidget()->addWidget(new RegisterPage);

    layout->addWidget(Global::getStackedWidget());

    Global::getStackedWidget()->setCurrentWidget(Global::getStackedWidget()->widget(0));
    Global::getStackedWidget()->currentWidget()->show();

    centralWidget->resize(727, 499);
    centralWidget->show();
    return app.exec();
}
