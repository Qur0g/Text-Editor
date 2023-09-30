#include "TitleBar.h"
#include "Scripts/WindowButtons/windowbutton.h"
#include "Scripts/WindowButtons/resizebutton.h"

#include <QMouseEvent>
#include <QScreen>
#include <QGuiApplication>

TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    m_mainLayout = new QHBoxLayout(this);
    //m_mainLayout = new QGridLayout(this);
    //m_mainLayout->setColumnMinimumWidth(0, 500);
    //m_mainLayout->setColumnMinimumWidth(2, 500);
    this->setLayout(m_mainLayout);

    setProperties();
    createWindowButtons();
}

void TitleBar::setProperties()
{   
    m_mainLayout->setSpacing(0);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);

    setAttribute(Qt::WA_StyledBackground);
    setAcceptDrops(true);
    setContextMenuPolicy(Qt::PreventContextMenu);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}

void TitleBar::createWindowButtons()
{
    //m_windowButtonsLayout = new QHBoxLayout();
    auto windowButtonsLayout = new QHBoxLayout();
    m_mainLayout->addLayout(windowButtonsLayout, 35);
    //m_mainLayout->addLayout(m_windowButtonsLayout, 0, 2);

    windowButtonsLayout->setAlignment(Qt::AlignRight | Qt::AlignTop);// | Qt::AlignHCenter);

    m_minimizeButton = new WindowButton(this, ":/icons/minimize.png");
    m_resizeButton = new ResizeButton(this);
    m_closeButton = new WindowButton(this, ":/icons/close.png");

    m_windowButtons.append(m_minimizeButton);
    m_windowButtons.append(m_resizeButton);
    m_windowButtons.append(m_closeButton);

    for(const auto& button : m_windowButtons)
    {
        windowButtonsLayout->addWidget(button);
        connect(button, &WindowButton::resizeWindowRequest, this, &TitleBar::resizeWindow);
    }

    m_closeButton->setStyleSheet("QPushButton { background-color: none; border: none; }"
                                "QPushButton:hover { background-color: red; }");
}

void TitleBar::setTitle(QString title)
{
    m_title = new QLabel(title, this);
    m_title->setContentsMargins(0, 0, 0, 0);
    m_title->setAlignment(Qt::AlignCenter);

    int windowCenter = (QGuiApplication::primaryScreen()->geometry().width() * 0.4) - m_title->width() / 2;
    m_title->move(windowCenter, 0);
}

void TitleBar::mousePressEvent(QMouseEvent* event)
{
    if ((event->button() == Qt::LeftButton) && (cursor().shape() == Qt::ArrowCursor))
        isDragging = true;

    else if(cursor().shape() != Qt::ArrowCursor)
        emit resizeWindow(event);
}

void TitleBar::dragEnterEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();
}

void TitleBar::dragMoveEvent(QDragMoveEvent* event)
{
    event->acceptProposedAction();
}

void TitleBar::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
}

void TitleBar::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    if(m_title != nullptr)
    {
        int windowCenter = (QGuiApplication::primaryScreen()->geometry().width() * 0.4) - m_title->width() / 2;
        m_title->move(windowCenter, 0);
    }
}

void TitleBar::mouseMoveEvent(QMouseEvent* event)
{
    if(isDragging)
        emit moveWindow();
}

void TitleBar::mouseReleaseEvent(QMouseEvent* event)
{
    isDragging = false;
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
        m_resizeButton->click();
}
