#include "mainwidget.h"
#include "titlebar.h"

#include <QApplication>

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    titleBar = new TitleBar(this);
    layout->addWidget(titleBar, 10);

    auto cont = new QWidget(this);
    layout->addWidget(cont, 90);
}
