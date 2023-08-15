#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "Scripts/basewindow.h"
#include <QHBoxLayout>

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

    QHBoxLayout* m_mainLayout;

    Menu* m_menu;
    MainWidget* m_mainWidget;
};
#endif // STARTWINDOW_H
