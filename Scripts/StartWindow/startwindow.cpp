#include "startwindow.h"
#include "menu.h"
#include "Scripts/titlebar.h"
#include "mainwidget.h"

StartWindow::StartWindow(QWidget *parent)
    : BaseWindow(parent)
{
    buildUI();

    makeConnections();
}

StartWindow::~StartWindow() = default;

void StartWindow::buildUI()
{
    BaseWindow::buildUI();

    mainLayout_ = new QHBoxLayout(containerWidget_);
    mainLayout_->setContentsMargins(0, 0, 0, 0);
    mainLayout_->setSpacing(0);

    menu_ = new Menu(containerWidget_);
    mainLayout_->addWidget(menu_, 10);

    mainWidget_ = new MainWidget(containerWidget_);
    mainLayout_->addWidget(mainWidget_, 90);
}

TitleBar* StartWindow::getTitleBar() const
{
    return mainWidget_->findChild<TitleBar*>();
}
