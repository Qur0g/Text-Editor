#include "startwindow.h"
#include "menu.h"
#include "titlebar.h"
#include "mainwidget.h"

#include <QScreen>
#include <QGuiApplication>
#include <QApplication>
#include <QHoverEvent>
#include <QPen>
#include <QPainter>
#include <QWindow>
#include <QMenuBar>

constexpr qreal border = 10;

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
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
    }
    //resize(800, 600);

    buildUI();

    makeConnections();
}

StartWindow::~StartWindow() = default;

void StartWindow::buildUI()
{
    containerWidget = new QWidget(this);
    setCentralWidget(containerWidget);
    //containerWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mainLayout = new QHBoxLayout(containerWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    //mainLayout->setAlignment(Qt::AlignLeft);

    menuWidget = new Menu(containerWidget);
    mainLayout->addWidget(menuWidget, 10);

    mainWidget = new MainWidget(containerWidget);
    mainLayout->addWidget(mainWidget, 100);
}

void StartWindow::makeConnections()
{
    auto titleBar = mainWidget->findChild<TitleBar*>();

    connect(titleBar, &TitleBar::moveWindow, this, [this] ()
            {
                this->windowHandle()->startSystemMove();
            });

    connect(titleBar, &TitleBar::resizeWindow, this, &StartWindow::mousePressEvent);

    connect(titleBar->closeButton, &QPushButton::clicked, [] ()
            {
                QApplication::quit();
            });

    connect(titleBar->resizeButton, &QPushButton::clicked, this, [this] ()
            {
                if(this->windowState() == Qt::WindowMaximized)
                    this->setWindowState(Qt::WindowNoState);
                else
                    this->setWindowState(Qt::WindowMaximized);
            });

    connect(titleBar->minimizeButton, &QPushButton::clicked, this, [this] ()
            {
                this->setWindowState(Qt::WindowMinimized);
            });
}

bool StartWindow::event(QEvent* event)
{
    if (event->type() == QEvent::HoverMove)
    {
        auto p = dynamic_cast<QHoverEvent*>(event)->position();

        if((p.y() < border) || (p.y() > (height() - border)))
        {
            if(p.x() < border)
            {
                if((p.y() < border))
                    setCursor(Qt::SizeFDiagCursor);
                else if(p.y() > (height() - border))
                    setCursor(Qt::SizeBDiagCursor);
            }
            else if(p.x() > (width() - border))
            {
                if(p.y() > (height() - border))
                    setCursor(Qt::SizeFDiagCursor);
                else if(p.y() < border)
                    setCursor(Qt::SizeBDiagCursor);
            }
            else
                setCursor(Qt::SizeVerCursor);
        }
        else if((p.x() < border) || (p.x() > (width() - border)))
            setCursor(Qt::SizeHorCursor);
        else
            setCursor(Qt::ArrowCursor);
    }

    else if(event->type() == QEvent::MouseButtonPress)
    {
        auto p = dynamic_cast<QMouseEvent*>(event)->pos();
        Qt::Edges edges;

        if(p.x() > width() - border)
            edges |= Qt::RightEdge;
        if(p.x() < border)
            edges |= Qt::LeftEdge;
        if(p.y() > height() - border)
            edges |= Qt::BottomEdge;
        if(p.y() < border)
            edges |= Qt::TopEdge;
        if(edges != 0)
        {
            this->windowHandle()->startSystemResize(edges);
        }
    }

    return QMainWindow::event(event);
}

/*void StartWindow::mousePressEvent(QMouseEvent* event)
{
    auto p = event->pos();
    //qDebug() << p;
    Qt::Edges edges;
    if(p.x() > width() - border)
        edges |= Qt::RightEdge;
    if(p.x() < border)
        edges |= Qt::LeftEdge;
    if(p.y() > height() - border)
        edges |= Qt::BottomEdge;
    if(p.y() < border)
        edges |= Qt::TopEdge;
    if(edges != 0)
    {
        this->windowHandle()->startSystemResize(edges);
    }
}*/

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
