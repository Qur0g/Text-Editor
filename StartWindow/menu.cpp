#include "menu.h"

Menu::Menu(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_StyledBackground);
    setStyleSheet("background-color: blue;");
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    menuLayout = new QVBoxLayout(this);
    //menuLayout->setContentsMargins(0, 0, 0, 0);

    createButtons();
}

void Menu::createButtons()
{
   //connectButtons();

    //buttons.append(homeButton);
   // buttons.append(newButton);
   // buttons.append(openButton);

    homeButton = createButton("Home", (Qt::CTRL | Qt::Key_H));
    newButton = createButton("New", (Qt::CTRL | Qt::Key_N));
    openButton = createButton("Open", (Qt::CTRL | Qt::Key_O));
}

QPushButton* Menu::createButton(QString name, QKeySequence shortcut)
{
    auto button = new QPushButton(name, this);
    button->setShortcut(shortcut);
    menuLayout->addWidget(button);

    return button;
}

//void Menu::connectButtons()
//{
    //connect(homeButton, SIGNAL(clicked()), this, SLOT())
//}
