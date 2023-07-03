#include "menu.h"

Menu::Menu(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_StyledBackground);
    setStyleSheet("background-color: blue;");

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    setFixedWidth(parent->width() * 0.1);

    menuLayout = new QVBoxLayout(this);

    createButtons();
    for(const auto button : buttons)
        menuLayout->addWidget(button);

}

void Menu::createButtons()
{
    homeButton = new QPushButton("Home", this);
    newButton = new QPushButton("New", this);
    openButton = new QPushButton("Open", this);

    homeButton->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_H));
    newButton->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    openButton->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));

    connectButtons();

    buttons.append(homeButton);
    buttons.append(newButton);
    buttons.append(openButton);
}

void Menu::connectButtons()
{
    //connect(homeButton, SIGNAL(clicked()), this, SLOT())
}
