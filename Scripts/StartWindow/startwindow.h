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

protected:

private:
    void buildUI() final;
    TitleBar* getTitleBar() const final;

    QHBoxLayout* mainLayout_;

    Menu* menu_;
    MainWidget* mainWidget_;
};
#endif // STARTWINDOW_H
