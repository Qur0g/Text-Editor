#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QMainWindow>

#include <QScrollArea>

class TitleBar;

class BaseWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = nullptr);

    static int m_border;

protected:
    bool event(QEvent *event) override;
    void dropEvent(QDropEvent *p_event) override;
    void dragEnterEvent(QDragEnterEvent *p_event) override;
    void dragMoveEvent(QDragMoveEvent *p_event) override;

    virtual void buildUI();
    virtual TitleBar* getTitleBar() const = 0;

    void makeConnections();

    QWidget* m_containerWidget;

private:
    void setProperties();

    int m_maxWidth = 600;
    int m_maxHeight = 400;
};

#endif // BASEWINDOW_H
