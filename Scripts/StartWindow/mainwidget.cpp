#include "mainwidget.h"
#include "Scripts/StartWindow/Contents/homecontent.h"
#include "Scripts/titlebar.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    m_layout = new QVBoxLayout(this);
    setLayout(m_layout);
    m_layout->setSpacing(0);
    m_layout->setContentsMargins(0, 0, 0, 0);

    m_titleBar = new TitleBar(this);
    m_layout->addWidget(m_titleBar, 10);
    m_titleBar->setTitle("Word");

    m_content = new HomeContent(this);
    m_layout->addWidget(m_content, 90);
}
