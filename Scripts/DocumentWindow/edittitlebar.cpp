#include "edittitlebar.h"
#include "Scripts/usersettings.h"
#include "qmenu.h"

#include <QMetaEnum>

EditTitleBar::EditTitleBar(QWidget* parent)
    : TitleBar(parent)
{
    m_quickAccessLayout = new QHBoxLayout();
    m_mainLayout->insertLayout(0, m_quickAccessLayout);
    m_quickAccessLayout->setAlignment(Qt::AlignTop);

    m_quickAccessButtons = UserSettings::loadQuickAccess();
    QMetaObject metaObject = EditTitleBar::staticMetaObject;

    for(const auto& button : m_quickAccessButtons)
    {
        int enumIndex = metaObject.enumerator
                       (EditTitleBar::staticMetaObject.indexOfEnumerator("ButtonType"))
                           .keyToValue(button.toUtf8().constData());

        EditTitleBar::ButtonType enumValue = static_cast<EditTitleBar::ButtonType>(enumIndex);

        addToQuickAccess(enumValue);
    }

    m_customizeQuickAccessButton = new QToolButton(this);
    m_quickAccessLayout->addWidget(m_customizeQuickAccessButton);
    m_customizeQuickAccessButton->setPopupMode(QToolButton::InstantPopup);

    auto menu = new QMenu(this);
    m_customizeQuickAccessButton->setMenu(menu);

    auto action1 = new QAction("xd", this);
    menu->addAction(action1);
    auto action2 = new QAction("xd", this);
    menu->addAction(action2);
    //m_customizeQuickAccessButton->setMenu(menu);
}

void EditTitleBar::addToQuickAccess(EditTitleBar::ButtonType enumNumber)
{
    auto button = new QPushButton(this);
    m_quickAccessLayout->addWidget(button);

    switch (enumNumber) {
    case AutoSave:

        break;
    default:
        break;
   }
}
