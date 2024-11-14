#ifndef HOMETAB_H
#define HOMETAB_H

#include "tab.h"

class HomeTab : public Tab
{
    Q_OBJECT
public:
    explicit HomeTab(QString name = "");
    HomeTab(QWidget* parent = nullptr, QString name = "");

    void displayContent() override;
    void hideContent() override;

signals:
    void pasteButtonClicked();
    void cutButtonClicked();
    void copyButtonClicked();
    void undoButtonClicked();
    void redoButtonClicked();
    void formatButtonClicked();

private:
    void createClipboardSection();
    void createFontSection();
};

#endif // HOMETAB_H
