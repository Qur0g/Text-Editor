#include "ribbon.h"
#include "Tabs/tab.h"
#include "Tabs/hometab.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QTabWidget>

Ribbon::Ribbon(QWidget *parent)
    : QWidget{parent}
{
    this->setAttribute(Qt::WA_StyledBackground);
    this->setStyleSheet("background-color: gray;");

    auto layout = new QVBoxLayout(this);
    this->setLayout(layout);

    //m_navigationLayout = new QHBoxLayout();
    //containerLayout->addLayout(m_navigationLayout);

    //m_navigationLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    //auto tabLayout = new QHBoxLayout();
    //containerLayout->addLayout(tabLayout);

    QTabWidget* tabWidget = new QTabWidget(this);
    layout->addWidget(tabWidget);

    //Tab* fileTab = new FileTab("File");
    Tab* homeTab = new HomeTab("Home");

    //tabWidget->addTab(fileTab, "File");
    tabWidget->addTab(homeTab, "Home");

    //homeTab->displayContent();
    //m_activeTab = homeTab;
}

/*Tab* Ribbon::createTab(QString name)
{
    auto tab = new Tab(name);
    tabWidget->addTab(tab, name);
    return tab;
}*/