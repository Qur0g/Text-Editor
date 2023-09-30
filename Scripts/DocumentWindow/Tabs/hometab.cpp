#include "hometab.h"

#include <QPushButton>
#include <QGridLayout>

HomeTab::HomeTab(QString name)
    : HomeTab(nullptr, name)
{}

HomeTab::HomeTab(QWidget* parent, QString name)
    : Tab{parent, name}
{
    this->setContentsMargins(-10, 0, 0, 0);


    createUndoRedoSection();
    createClipboardSection();
}

void HomeTab::displayContent()
{

}

void HomeTab::hideContent()
{

}

void HomeTab::createUndoRedoSection()
{
    auto* sectionLayout = new QVBoxLayout();
    m_mainLayout->addLayout(sectionLayout);

    auto* undo = new QPushButton("Undo", this);
    auto* redo = new QPushButton("Redo", this);

    sectionLayout->addWidget(undo);
    sectionLayout->addWidget(redo);
}

void HomeTab::createClipboardSection()
{
    auto* sectionLayout = new QGridLayout();
    m_mainLayout->addLayout(sectionLayout);

    auto* paste = new QPushButton("Paste", this);
    auto* cut = new QPushButton("Cut");
    auto* copy = new QPushButton("Copy", this);
    auto* formatPainter = new QPushButton("Painter", this);

    sectionLayout->addWidget(paste, 0, 0);
    sectionLayout->addWidget(cut, 0, 1);
    sectionLayout->addWidget(copy, 1, 0);
    sectionLayout->addWidget(formatPainter, 1, 1);
}
