#include "hometab.h"

#include <QPushButton>
#include <QGridLayout>
#include <QFrame>

HomeTab::HomeTab(QString name)
    : HomeTab(nullptr, name)
{}

HomeTab::HomeTab(QWidget* parent, QString name)
    : Tab{parent, name}
{
    this->setContentsMargins(0, 0, 0, 0);

    createClipboardSection();

    QFrame* line;
    line = new QFrame(this);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setStyleSheet("background-color: red;");
    m_mainLayout->addWidget(line);

    createFontSection();
}

void HomeTab::displayContent()
{

}

void HomeTab::hideContent()
{

}

void HomeTab::createClipboardSection()
{
    auto* sectionLayout = new QGridLayout(this);
    m_mainLayout->addLayout(sectionLayout, 5);

    auto* paste = new QPushButton("Paste", this);
    auto* copy = new QPushButton("Copy", this);
    auto* cut = new QPushButton("Cutzzzzzzzzz", this);
    //auto* undo = new QPushButton("Undo", this);
    //auto* redo = new QPushButton("Redo", this);
    auto* formatPainter = new QPushButton("Painter", this);

    sectionLayout->addWidget(paste, 0, 0, 3, 1, Qt::AlignLeft);
    sectionLayout->addWidget(cut, 0, 1, Qt::AlignLeft);
    sectionLayout->addWidget(copy, 1, 1, Qt::AlignLeft);
    //sectionLayout->
    //sectionLayout->addWidget(undo, 0, 2, Qt::AlignLeft);
    //sectionLayout->addWidget(redo, 1, 2, Qt::AlignLeft);
    sectionLayout->addWidget(formatPainter, 2, 1, 1, 2, Qt::AlignLeft);

    auto buttons = new QVector<QPushButton*>();
    buttons->append(paste);
    buttons->append(copy);
    buttons->append(cut);
    //buttons->append(undo);
    //buttons->append(redo);
    buttons->append(formatPainter);

    for(const auto& button : *buttons)
    {
        //button->setMinimumWidth(25);
        //button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        //button->adjustSize();
    }

    connect(paste, &QPushButton::clicked, this, &HomeTab::pasteButtonClicked);
    connect(copy, &QPushButton::clicked, this, &HomeTab::copyButtonClicked);
    connect(cut, &QPushButton::clicked, this, &HomeTab::cutButtonClicked);
    //connect(undo, &QPushButton::clicked, this, &HomeTab::undoButtonClicked);
    //connect(redo, &QPushButton::clicked, this, &HomeTab::redoButtonClicked);
    //connect(formatPainter, &QPushButton::clicked, this, &HomeTab::formatPainterButtonClicked);
}

void HomeTab::createFontSection()
{
    auto* sectionLayout = new QGridLayout(this);
    m_mainLayout->addLayout(sectionLayout, 95);
    auto b = new QWidget();
    sectionLayout->addWidget(b);
    b->setStyleSheet("background-color: red;");
}
