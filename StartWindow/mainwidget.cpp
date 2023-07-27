#include "mainwidget.h"
#include "Contents/homecontent.h"
#include "titlebar.h"

#include <QApplication>

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    layout_ = new QVBoxLayout(this);
    layout_->setSpacing(0);
    layout_->setContentsMargins(0, 0, 0, 0);

    titleBar_ = new TitleBar(this);
    layout_->addWidget(titleBar_, 10);

    content_ = new HomeContent(this);
    layout_->addWidget(content_, 90);
}
