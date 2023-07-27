#include "titlebar.h"
#include "Buttons/windowbutton.h"
#include "Buttons/resizebutton.h"

#include <QMouseEvent>
#include <QMimeData>
#include <QDebug>
#include <QApplication>
#include <QToolButton>
#include <QAction>
#include <QToolBar>

TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    mainLayout_ = new QHBoxLayout(this);
    labelLayout_ = new QVBoxLayout();
    buttonsLayout_ = new QHBoxLayout();
    mainLayout_->addLayout(labelLayout_);
    mainLayout_->addLayout(buttonsLayout_);

    title_ = new QLabel("Word");

    labelLayout_->addWidget(title_, 0, Qt::AlignCenter | Qt::AlignTop);

    setProperties();
    createButtons();
}

void TitleBar::setProperties()
{
    mainLayout_->setSpacing(0);
    mainLayout_->setContentsMargins(0, 0, 0, 0);

    buttonsLayout_->setAlignment(Qt::AlignTop);

    setAttribute(Qt::WA_StyledBackground);
    setAcceptDrops(true);
    setContextMenuPolicy(Qt::PreventContextMenu);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}

void TitleBar::createButtons()
{
    minimizeButton_ = new WindowButton(this, ":/icons/minimize.png");
    buttonsLayout_->addWidget(minimizeButton_);

    resizeButton_ = new ResizeButton(this);
    buttonsLayout_->addWidget(resizeButton_);

    closeButton_ = new WindowButton(this, ":/icons/close.png");
    buttonsLayout_->addWidget(closeButton_);
    closeButton_->setStyleSheet("QPushButton { background-color: none; border: none; }"
                          "QPushButton:hover { background-color: red; }");

    buttons_.append(minimizeButton_);
    buttons_.append(resizeButton_);
    buttons_.append(closeButton_);

    for(const auto& button : buttons_)
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
