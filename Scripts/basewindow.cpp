#include "basewindow.h"
#include "Scripts/titlebar.h"
#include "Scripts/WindowButtons/windowbutton.h"
#include "Scripts/WindowButtons/resizebutton.h"

#include <QScreen>
#include <QGuiApplication>
#include <QApplication>
#include <QHoverEvent>
#include <QWindow>

int BaseWindow::m_border = 10;

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

    QList<QScreen*> screens = QGuiApplication::screens();

    if (!screens.isEmpty()) {
        QScreen *screen = screens.first();
        QRect screenGeometry = screen->availableGeometry();
        setGeometry(screenGeometry);

        m_maxHeight = height();
        m_maxWidth = width();
    }

    setWindowState(Qt::WindowMaximized);
}

void BaseWindow::buildUI()
{
    m_containerWidget = new QWidget(this);
    setCentralWidget(m_containerWidget);
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

    connect(titleBar->m_minimizeButton, &QPushButton::clicked, this, [this] ()
            {
                this->setWindowState(Qt::WindowMinimized);
            });

    connect(titleBar->m_resizeButton, &QPushButton::clicked, this, [this] ()
            {
                if(this->windowState() == Qt::WindowMaximized)
                    this->setWindowState(Qt::WindowNoState);                   
                else
                    this->setWindowState(Qt::WindowMaximized);
            });

    connect(titleBar->m_closeButton, &QPushButton::clicked, [] ()
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

            if((p.y() < m_border) || (p.y() > (height() - m_border)))
            {
                if(p.x() < m_border)
                {
                    if((p.y() < m_border))
                        setCursor(Qt::SizeFDiagCursor);
                    else if(p.y() > (height() - m_border))
                        setCursor(Qt::SizeBDiagCursor);
                }
                else if(p.x() > (width() - m_border))
                {
                    if(p.y() > (height() - m_border))
                        setCursor(Qt::SizeFDiagCursor);
                    else if(p.y() < m_border)
                        setCursor(Qt::SizeBDiagCursor);
                }
                else
                    setCursor(Qt::SizeVerCursor);
            }
            else if((p.x() < m_border) || (p.x() > (width() - m_border)))
                setCursor(Qt::SizeHorCursor);
            else
                setCursor(Qt::ArrowCursor);

            return true;
        }

        else if(event->type() == QEvent::MouseButtonPress)
        {
            auto p = dynamic_cast<QMouseEvent*>(event)->pos();
            Qt::Edges edges;

            if(p.x() > width() - m_border)
                edges |= Qt::RightEdge;
            if(p.x() < m_border)
                edges |= Qt::LeftEdge;
            if(p.y() > height() - m_border)
                edges |= Qt::BottomEdge;
            if(p.y() < m_border)
                edges |= Qt::TopEdge;
            if(edges != 0)
            {
                this->windowHandle()->startSystemResize(edges);
            }

            return true;
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
