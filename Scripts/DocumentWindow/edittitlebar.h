#ifndef EDITTITLEBAR_H
#define EDITTITLEBAR_H

#include <Scripts/titlebar.h>

#include <QToolButton>

class EditTitleBar : public TitleBar
{
    Q_OBJECT
public:
    EditTitleBar(QWidget* parent = nullptr);

    enum ButtonType
    {
        AutoSave,
        Save,
        Undo,
        Redo,
        Idk
    };
    Q_ENUM(ButtonType);

private:
    void addToQuickAccess(ButtonType);

    QHBoxLayout* m_quickAccessLayout;

    QList<QString> m_quickAccessButtons;

    QToolButton* m_customizeQuickAccessButton;
};

#endif // EDITTITLEBAR_H
