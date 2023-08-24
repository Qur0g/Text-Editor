#include "menu.h"

Menu::Menu(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_StyledBackground);
    setStyleSheet("background-color: blue;");
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    m_menuLayout = new QVBoxLayout(this);
    m_menuLayout->setSpacing(0);

    createButtons();
}

void Menu::createButtons()
{
   //connectButtons();

    //buttons.append(homeButton);
   // buttons.append(newButton);
   // buttons.append(openButton);

    m_homeButton = createButton("Home", (Qt::CTRL | Qt::Key_H));
    m_newButton = createButton("New", (Qt::CTRL | Qt::Key_N));
    m_openButton = createButton("Open", (Qt::CTRL | Qt::Key_O));
}

QPushButton* Menu::createButton(QString name, QKeySequence shortcut)
{
    auto button = new QPushButton(name, this);
    button->setShortcut(shortcut);
    m_menuLayout->addWidget(button);

    return button;
}
