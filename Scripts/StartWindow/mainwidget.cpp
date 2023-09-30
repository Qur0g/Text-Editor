#include "mainwidget.h"
#include "Scripts/StartWindow/Contents/homecontent.h"
#include "Scripts/titlebar.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    auto layout = new QVBoxLayout(this);
    setLayout(layout);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    m_titleBar = new TitleBar(this);
    layout->addWidget(m_titleBar, 10);
    m_titleBar->setTitle("Word");

    m_content = new HomeContent(this);
    layout->addWidget(m_content, 90);
}
