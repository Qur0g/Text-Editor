#include "windowbutton.h"
#include "Scripts/basewindow.h"
#include "qdebug.h"

#include <QEvent>

WindowButton::WindowButton(QWidget* parent, QString iconPath)
    : QPushButton(parent), m_iconPath(iconPath)
{
    setProperties();
}

void WindowButton::setProperties()
{
    setFixedHeight(m_height);
    setFixedWidth(m_width);
    setStyleSheet("QPushButton { background-color: none; border: none; }"
                  "QPushButton:hover { background-color: gray; }");
    setIcon(QIcon(m_iconPath));
}

bool WindowButton::event(QEvent* event)
{
    if (event->type() == QEvent::Enter)
        BaseWindow::m_border = 2;
    if(event->type() == QEvent::Leave)
        BaseWindow::m_border = 10;

    return QPushButton::event(event);
}

void WindowButton::mousePressEvent(QMouseEvent* event)
{
    if(cursor().shape() != Qt::ArrowCursor)
        emit resizeWindowRequest(event);
    else
        QPushButton::mousePressEvent(event);
}
