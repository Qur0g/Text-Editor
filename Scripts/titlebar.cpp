#include "titlebar.h"
#include "Scripts/WindowButtons/windowbutton.h"
#include "Scripts/WindowButtons/resizebutton.h"

#include <QMouseEvent>
#include <QDebug>

TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    mainLayout_ = new QHBoxLayout(this);
    labelLayout_ = new QVBoxLayout();
    windowButtonsLayout_ = new QHBoxLayout();
    mainLayout_->addLayout(labelLayout_);
    mainLayout_->addLayout(windowButtonsLayout_);

    title_ = new QLabel("Word");

    labelLayout_->addWidget(title_, 0, Qt::AlignCenter | Qt::AlignTop);

    setProperties();
    createButtons();
}

void TitleBar::setProperties()
{
    mainLayout_->setSpacing(0);
    mainLayout_->setContentsMargins(0, 0, 0, 0);

    windowButtonsLayout_->setAlignment(Qt::AlignTop);

    setAttribute(Qt::WA_StyledBackground);
    setAcceptDrops(true);
    setContextMenuPolicy(Qt::PreventContextMenu);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}

void TitleBar::createButtons()
{
    minimizeButton_ = new WindowButton(this, ":/icons/minimize.png");
    windowButtonsLayout_->addWidget(minimizeButton_);

    resizeButton_ = new ResizeButton(this);
    windowButtonsLayout_->addWidget(resizeButton_);

    closeButton_ = new WindowButton(this, ":/icons/close.png");
    windowButtonsLayout_->addWidget(closeButton_);
    closeButton_->setStyleSheet("QPushButton { background-color: none; border: none; }"
                          "QPushButton:hover { background-color: red; }");

    windowButtons_.append(minimizeButton_);
    windowButtons_.append(resizeButton_);
    windowButtons_.append(closeButton_);

    for(const auto& button : windowButtons_)
    {
        connect(button, &WindowButton::resizeWindowRequest, this, &TitleBar::resizeWindow);
    }
}

void TitleBar::mousePressEvent(QMouseEvent* event)
{
    if(cursor().shape() == Qt::ArrowCursor)
        emit moveWindow();
    else
        emit resizeWindow(event);
}

void TitleBar::dragEnterEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();
}

void TitleBar::dragMoveEvent(QDragMoveEvent* event) {
    event->acceptProposedAction();
}

void TitleBar::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
}
