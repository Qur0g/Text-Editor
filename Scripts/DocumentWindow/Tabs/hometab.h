#ifndef HOMETAB_H
#define HOMETAB_H

#include "tab.h"

class HomeTab : public Tab
{
public:
    explicit HomeTab(QString name = "");
    HomeTab(QWidget* parent = nullptr, QString name = "");

    void displayContent() override;
    void hideContent() override;

private:
    void createUndoRedoSection();
    void createClipboardSection();
};

#endif // HOMETAB_H
