#include "titlebar.h"
#include "startwindow.h"

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
    titleBarLayout = new QHBoxLayout(this);
    setProperties();
    createButtons();
}

void TitleBar::setProperties()
{
    setAttribute(Qt::WA_StyledBackground);
    setAcceptDrops(true);
    setContextMenuPolicy(Qt::PreventContextMenu);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}

void TitleBar::createButtons()
{
    minimizeButton = new QPushButton("minimize", this);
    resizeButton = new QPushButton("resize", this);
    closeButton = new QPushButton("close", this);

    titleBarLayout->addWidget(minimizeButton);
    titleBarLayout->addWidget(resizeButton);
    titleBarLayout->addWidget(closeButton);
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
    // format string: iconname;text

    /*auto dataStrings = event->mimeData()->text().split(";");
    auto act_icon = dataStrings.first();
    auto act_name = dataStrings.at(1);

    auto tempBtn = new QToolButton;

    tempBtn->setDefaultAction(new QAction(QIcon::fromTheme(act_icon),act_name));

    if (act_name == "kde"){
        connect(tempBtn->defaultAction(),&QAction::triggered, [] ()
                {
                    qDebug()<<"kde_pressed";
                });
    } else if (act_name == "okular") {
        connect(tempBtn->defaultAction(),&QAction::triggered, [] ()
                {
                    qDebug()<<"okular pressed";
                });
    }

    //addWidget(tempBtn);

    event->accept();*/
}
