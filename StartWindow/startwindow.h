#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>

class Menu;
class TitleBar;
class MainWidget;

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

    bool event(QEvent *event) override;

    void dropEvent(QDropEvent *p_event) override;
    void dragEnterEvent(QDragEnterEvent *p_event) override;
    void dragMoveEvent(QDragMoveEvent *p_event) override;

protected:
    //void mousePressEvent(QMouseEvent* event) override;

private slots:

private:
    void buildUI();
    void makeConnections();

    QWidget* containerWidget;
    QHBoxLayout* mainLayout;

    Menu* menuWidget;
    MainWidget* mainWidget;
};
#endif // STARTWINDOW_H
