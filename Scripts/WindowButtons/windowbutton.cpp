#include "windowbutton.h"
#include "Scripts/basewindow.h"

#include <QEvent>

WindowButton::WindowButton(QWidget* parent, QString iconPath)
    : QPushButton(parent), iconPath_(iconPath)
{
    setProperties();
}

void WindowButton::setProperties()
{
    setFixedHeight(height_);
    setFixedWidth(width_);
    setStyleSheet("QPushButton { background-color: none; border: none; }"
                  "QPushButton:hover { background-color: gray; }");
    setIcon(QIcon(iconPath_));
}

bool WindowButton::event(QEvent* event)
{
    if (event->type() == QEvent::Enter)
        BaseWindow::border_ = 2;
    if(event->type() == QEvent::Leave)
        BaseWindow::border_ = 10;

    return QPushButton::event(event);
}

void WindowButton::mousePressEvent(QMouseEvent* event)
{
    if(cursor().shape() != Qt::ArrowCursor)
        emit resizeWindowRequest(event);
    else
        QPushButton::mousePressEvent(event);
}
