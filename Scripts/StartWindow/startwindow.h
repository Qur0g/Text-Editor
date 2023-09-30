#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "Scripts/basewindow.h"

class Menu;
class MainWidget;

class StartWindow : public BaseWindow
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private:
    void buildUI() final;
    TitleBar* getTitleBar() const final;

    Menu* m_menu;
    MainWidget* m_mainWidget;
};
#endif // STARTWINDOW_H
