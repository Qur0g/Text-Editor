#include "menu.h"

Menu::Menu(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_StyledBackground);
    setStyleSheet("background-color: blue;");
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    menuLayout_ = new QVBoxLayout(this);
    menuLayout_->setSpacing(0);

    createButtons();
}

void Menu::createButtons()
{
   //connectButtons();

    //buttons.append(homeButton);
   // buttons.append(newButton);
   // buttons.append(openButton);

    homeButton_ = createButton("Home", (Qt::CTRL | Qt::Key_H));
    newButton_ = createButton("New", (Qt::CTRL | Qt::Key_N));
    openButton_ = createButton("Open", (Qt::CTRL | Qt::Key_O));
}

QPushButton* Menu::createButton(QString name, QKeySequence shortcut)
{
    auto button = new QPushButton(name, this);
    button->setShortcut(shortcut);
    menuLayout_->addWidget(button);

    return button;
}
