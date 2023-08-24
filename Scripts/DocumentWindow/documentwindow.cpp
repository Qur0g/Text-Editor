#include "documentwindow.h"
#include "edittitlebar.h"

DocumentWindow::DocumentWindow(QWidget *parent)
    : BaseWindow{parent}
{
    buildUI();
    makeConnections();
}

void DocumentWindow::buildUI()
{
    BaseWindow::buildUI();

    m_mainLayout = new QVBoxLayout(m_containerWidget);
    //this->setLayout(mainLayout_);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->setSpacing(0);

    m_titleBar = new EditTitleBar(this);
    m_mainLayout->addWidget(m_titleBar, 5);

    auto d = new QWidget(this);
    m_mainLayout->addWidget(d, 95);
}

TitleBar* DocumentWindow::getTitleBar() const
{
    return m_titleBar;
}




