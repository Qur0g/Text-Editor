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

    static int border_;

protected:
    //void mousePressEvent(QMouseEvent* event) override;

private slots:

private:
    void setProperties();
    void buildUI();
    void makeConnections();

    QWidget* containerWidget_;
    QHBoxLayout* mainLayout_;

    Menu* menuWidget_;
    MainWidget* mainWidget_;

    int maxWidth_;
    int maxHeight_;
};
#endif // STARTWINDOW_H
