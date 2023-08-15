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

    m_mainLayout = new QHBoxLayout(m_containerWidget);
    this->setLayout(m_mainLayout);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->setSpacing(0);

    m_menu = new Menu(m_containerWidget);
    m_mainLayout->addWidget(m_menu, 10);

    m_mainWidget = new MainWidget(m_containerWidget);
    m_mainLayout->addWidget(m_mainWidget, 90);
}

TitleBar* StartWindow::getTitleBar() const
{
    return m_mainWidget->findChild<TitleBar*>();
}
