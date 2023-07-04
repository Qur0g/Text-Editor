#include "startwindow.h"
#include "menu.h"
#include "Contents/homecontent.h"
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
    mainWidget->setStyleSheet("background-color: red;");

    mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->setAlignment(Qt::AlignLeft);

    menuWidget = new Menu(mainWidget);
    mainLayout->addWidget(menuWidget);

    //mainWidget->setLayout(mainLayout);

    //contentWidget = new HomeContent(mainWidget);
    //mainLayout->addWidget(contentWidget);
}

StartWindow::~StartWindow()
{
}

