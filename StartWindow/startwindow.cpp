#include "startwindow.h"
#include "menu.h"
#include "titlebar.h"
#include "mainwidget.h"
#include "Buttons/windowbutton.h"
#include "Buttons/resizebutton.h"

#include <QScreen>
#include <QGuiApplication>
#include <QApplication>
#include <QHoverEvent>
#include <QPen>
#include <QPainter>
#include <QWindow>
#include <QMenuBar>

int StartWindow::border_ = 10;

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setProperties();

    buildUI();

    makeConnections();
}

StartWindow::~StartWindow() = default;

void StartWindow::setProperties()
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

void StartWindow::buildUI()
{
    containerWidget_ = new QWidget(this);
    setCentralWidget(containerWidget_);

    mainLayout_ = new QHBoxLayout(containerWidget_);
    mainLayout_->setContentsMargins(0, 0, 0, 0);
    mainLayout_->setSpacing(0);

    menuWidget_ = new Menu(containerWidget_);
    mainLayout_->addWidget(menuWidget_, 10);

    mainWidget_ = new MainWidget(containerWidget_);
    mainLayout_->addWidget(mainWidget_, 90);
}

void StartWindow::makeConnections()
{
    auto titleBar = mainWidget_->findChild<TitleBar*>();

    connect(titleBar, &TitleBar::moveWindow, this, [this] ()
            {
                this->windowHandle()->startSystemMove();

                if(this->windowState() == Qt::WindowMaximized)
                    this->setWindowState(Qt::WindowNoState);
            });

    connect(titleBar, &TitleBar::resizeWindow, this, &StartWindow::mousePressEvent);

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

bool StartWindow::event(QEvent* event)
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

void StartWindow::dragEnterEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();
}

void StartWindow::dragMoveEvent(QDragMoveEvent* event)
{
    event->acceptProposedAction();
}

void StartWindow::dropEvent(QDropEvent* event)
{
    event->acceptProposedAction();
}
