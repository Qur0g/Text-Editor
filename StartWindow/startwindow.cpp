#include "startwindow.h"
#include "menu.h"
//#include "Contents/homecontent.h"
#include <QScreen>
#include <QGuiApplication>

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);

    QList<QScreen*> screens = QGuiApplication::screens();

    if (!screens.isEmpty()) {
        QScreen *screen = screens.first();
        QRect screenGeometry = screen->availableGeometry();
        setGeometry(screenGeometry);
    }

    mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);
    mainWidget->setFixedHeight(height());
    mainWidget->setFixedWidth(width());
    mainWidget->setStyleSheet("background-color: green;");

    mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    menuWidget = new Menu(mainWidget);
    mainLayout->addWidget(menuWidget);

    //contentWidget = new HomeContent(mainWidget);
    //mainLayout->addWidget(contentWidget);
}

StartWindow::~StartWindow()
{
}

