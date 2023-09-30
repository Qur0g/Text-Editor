#include "documentwindow.h"
#include "edittitlebar.h"
#include "ribbon.h"
#include "workspace.h"

#include <QScrollArea>

DocumentWindow::DocumentWindow(QWidget *parent)
    : BaseWindow{parent}
{
    buildUI();
    makeConnections();
}

void DocumentWindow::buildUI()
{
    BaseWindow::buildUI();

    this->setStyleSheet("background-color: lightgray;");

    m_mainLayout = new QVBoxLayout(m_containerWidget);

    //this->setLayout(mainLayout_);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->setSpacing(0);

    m_titleBar = new EditTitleBar(m_containerWidget);
    m_mainLayout->addWidget(m_titleBar, 5);

    m_ribbon = new Ribbon(m_containerWidget);
    m_mainLayout->addWidget(m_ribbon, 10);

    auto scroll = new QScrollArea(m_containerWidget);
    //scroll->setStyleSheet("background-color: green;");
    scroll->setWidgetResizable(true);
    m_mainLayout->addWidget(scroll, 85);

    auto workspaceContainer = new QWidget(scroll);
    scroll->setWidget(workspaceContainer);

    auto workspaceLayout = new QVBoxLayout(workspaceContainer);

    m_workspace = new Workspace(scroll);
    workspaceLayout->addWidget(m_workspace, 0, Qt::AlignHCenter);
}

TitleBar* DocumentWindow::getTitleBar() const
{
    return m_titleBar;
}




