#ifndef EDITTITLEBAR_H
#define EDITTITLEBAR_H

#include <Scripts/titlebar.h>

#include <QToolButton>
#include <QLineEdit>

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

protected:
    void resizeEvent(QResizeEvent*) override;

private slots:
    void performSearch();
    void updateSearchResults(const QString& text);

private:
    void createQuickAccess();
    void addToQuickAccess(ButtonType& type);
    void createSearchBar();

    QHBoxLayout* m_quickAccessLayout;
    QList<QAbstractButton*> m_quickAccessButtons;
    QToolButton* m_customizeQuickAccessButton;

    QLineEdit* m_searchLineEdit;
    QLabel *resultLabel;
};

#endif // EDITTITLEBAR_H
