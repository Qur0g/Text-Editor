#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>

class Menu;

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:

private:
    QWidget* mainWidget;
    QHBoxLayout* mainLayout;

    Menu* menuWidget;
    QWidget* contentWidget;
};
#endif // STARTWINDOW_H
