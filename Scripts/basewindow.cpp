#include "basewindow.h"
#include "Scripts/titlebar.h"
#include "Scripts/WindowButtons/windowbutton.h"
#include "Scripts/WindowButtons/resizebutton.h"

#include <QScreen>
#include <QGuiApplication>
#include <QApplication>
#include <QHoverEvent>
#include <QWindow>

int BaseWindow::border_ = 10;

BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setProperties();
}

void BaseWindow::setProperties()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAcceptDrops(true);
    setAttribute(Qt::WA_Hover);
    setMinimumSize(600, 400);
    setWindowState(Qt::WindowMaximized);

    QList<QScreen*> screens = QGuiApplication::screens();

    if (!screens.isEmpty()) {
        QScreen *screen = screens.first();
        QRect screenGeometry = screen->availableGeometry();
        setGeometry(screenGeometry);

        maxHeight_ = height();
        maxWidth_ = width();
    }
}

void BaseWindow::buildUI()
{
    containerWidget_ = new QWidget(this);
    setCentralWidget(containerWidget_);
}

void BaseWindow::makeConnections()
{
    auto titleBar = getTitleBar();

    connect(titleBar, &TitleBar::moveWindow, this, [this] ()
            {
                this->windowHandle()->startSystemMove();

                if(this->windowState() == Qt::WindowMaximized)
                    this->setWindowState(Qt::WindowNoState);
            });

    connect(titleBar, &TitleBar::resizeWindow, this, &BaseWindow::mousePressEvent);

    connect(titleBar->minimizeButton_, &QPushButton::clicked, this, [this] ()
            {
                this->setWindowState(Qt::WindowMinimized);
            });

    connect(titleBar->resizeButton_, &QPushButton::clicked, this, [this] ()
            {
                if(this->windowState() == Qt::WindowMaximized)
                {
                    this->setWindowState(Qt::WindowNoState);

                    if((width() == maxWidth_) && (height() == maxHeight_))
                        resize(maxWidth_ * 0.75, maxHeight_ * 0.75);
                }
                else
                    this->setWindowState(Qt::WindowMaximized);
            });

    connect(titleBar->closeButton_, &QPushButton::clicked, [] ()
            {
                QApplication::quit();
            });
}

bool BaseWindow::event(QEvent* event)
{
    if(this->windowState() != Qt::WindowMaximized)
    {
        if (event->type() == QEvent::HoverMove)
        {
            auto p = dynamic_cast<QHoverEvent*>(event)->position();

            if((p.y() < border_) || (p.y() > (height() - border_)))
            {
                if(p.x() < border_)
                {
                    if((p.y() < border_))
                        setCursor(Qt::SizeFDiagCursor);
                    else if(p.y() > (height() - border_))
                        setCursor(Qt::SizeBDiagCursor);
                }
                else if(p.x() > (width() - border_))
                {
                    if(p.y() > (height() - border_))
                        setCursor(Qt::SizeFDiagCursor);
                    else if(p.y() < border_)
                        setCursor(Qt::SizeBDiagCursor);
                }
                else
                    setCursor(Qt::SizeVerCursor);
            }
            else if((p.x() < border_) || (p.x() > (width() - border_)))
                setCursor(Qt::SizeHorCursor);
            else
                setCursor(Qt::ArrowCursor);
        }

        else if(event->type() == QEvent::MouseButtonPress)
        {
            auto p = dynamic_cast<QMouseEvent*>(event)->pos();
            Qt::Edges edges;

            if(p.x() > width() - border_)
                edges |= Qt::RightEdge;
            if(p.x() < border_)
                edges |= Qt::LeftEdge;
            if(p.y() > height() - border_)
                edges |= Qt::BottomEdge;
            if(p.y() < border_)
                edges |= Qt::TopEdge;
            if(edges != 0)
            {
                this->windowHandle()->startSystemResize(edges);
            }
        }
    }

    return QMainWindow::event(event);
}

void BaseWindow::dragEnterEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();
}

void BaseWindow::dragMoveEvent(QDragMoveEvent* event)
{
    event->acceptProposedAction();
}

void BaseWindow::dropEvent(QDropEvent* event)
{
    event->acceptProposedAction();
}
