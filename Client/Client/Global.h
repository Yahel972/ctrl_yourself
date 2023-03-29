#pragma once

#include <QStackedWidget>

class Global {
public:
    static QStackedWidget* getStackedWidget() {
        static QStackedWidget* stackedWidget = new QStackedWidget();
        return stackedWidget;
    }
};
