#include "edittitlebar.h"
#include "Scripts/usersettings.h"
#include "qmenu.h"

#include <QMetaEnum>

EditTitleBar::EditTitleBar(QWidget* parent)
    : TitleBar(parent)
{
    setAttribute(Qt::WA_StyledBackground);
    setStyleSheet("background-color: blue;");
    createQuickAccess();
    createSearchBar();
}

void EditTitleBar::createQuickAccess()
{
    m_quickAccessLayout = new QHBoxLayout();
    m_mainLayout->insertLayout(0, m_quickAccessLayout, 35);
    //m_mainLayout->addLayout(m_quickAccessLayout, 0, 0);
    m_quickAccessLayout->setAlignment(Qt::AlignLeft | Qt::AlignBottom);// | Qt::AlignHCenter);

    QList<QString> loadedButtons = UserSettings::loadQuickAccess();
    QMetaObject metaObject = EditTitleBar::staticMetaObject;

    for(const auto& button : loadedButtons)
    {
        int enumIndex = metaObject.enumerator
                        (EditTitleBar::staticMetaObject.indexOfEnumerator("ButtonType"))
                            .keyToValue(button.toUtf8().constData());

        EditTitleBar::ButtonType enumValue = static_cast<EditTitleBar::ButtonType>(enumIndex);

        addToQuickAccess(enumValue);//addToQuickAccess(enumValue);addToQuickAccess(enumValue);//addToQuickAccess(enumValue);
    }

    m_customizeQuickAccessButton = new QToolButton(this);
    m_quickAccessLayout->addWidget(m_customizeQuickAccessButton);
    m_customizeQuickAccessButton->setPopupMode(QToolButton::InstantPopup);

    auto menu = new QMenu(m_customizeQuickAccessButton);
    m_customizeQuickAccessButton->setMenu(menu);

    m_quickAccessButtons.append(m_customizeQuickAccessButton);

    for(const auto& button : m_quickAccessButtons)
    {
        button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        button->setMaximumWidth(50);
    }

    m_quickAccessLayout->setContentsMargins(0, 5, 0, 0);

    auto action1 = new QAction("xd");
    action1->setCheckable(true);
    menu->addAction(action1);
    auto action2 = new QAction("xd");
    menu->addAction(action2);
    //m_customizeQuickAccessButton->setMenu(menu);
}

void EditTitleBar::addToQuickAccess(EditTitleBar::ButtonType& type)
{
    auto button = new QPushButton(this);
    m_quickAccessLayout->addWidget(button);

    switch (type) {
    case AutoSave:

        break;
    default:
        break;
   }

    m_quickAccessButtons.append(button);
}

void EditTitleBar::createSearchBar()
{
   auto searchbarLayout = new QHBoxLayout();

   m_mainLayout->insertLayout(1, searchbarLayout, 30);
   //m_mainLayout->addLayout(searchbarLayout, 0, 1);
   searchbarLayout->setAlignment(Qt::AlignHCenter);

   m_searchLineEdit = new QLineEdit(this);
   searchbarLayout->addWidget(m_searchLineEdit);
   m_searchLineEdit->setFixedWidth(200);

   //int windowCenter = (window()->width() * 0.5); //- m_title->width();
   //m_searchLineEdit->move(windowCenter, m_searchLineEdit->pos().y());

   //resultLabel = new QLabel(this);
   //l->addWidget(resultLabel);

   //connect(searchButton, &QPushButton::clicked, this, &EditTitleBar::performSearch);
   connect(m_searchLineEdit, &QLineEdit::textChanged, this, &EditTitleBar::updateSearchResults);
   //m_searchLineEdit->move(100, 0);
}

void EditTitleBar::performSearch()
{
   QString searchTerm = m_searchLineEdit->text();
   QString searchResult = "Search results for: " + searchTerm;
   resultLabel->setText(searchResult);
}

void EditTitleBar::updateSearchResults(const QString& text)
{

}

void EditTitleBar::resizeEvent(QResizeEvent* event)
{
   TitleBar::resizeEvent(event);

   int windowCenter = (window()->width() * 0.5); //- m_title->width();
   //m_searchLineEdit->move(windowCenter, 0);
}
