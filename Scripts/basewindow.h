#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QMainWindow>

class TitleBar;

class BaseWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = nullptr);

    static int border_;

signals:

protected:
    bool event(QEvent *event) override;
    void dropEvent(QDropEvent *p_event) override;
    void dragEnterEvent(QDragEnterEvent *p_event) override;
    void dragMoveEvent(QDragMoveEvent *p_event) override;

    virtual void buildUI();
    virtual TitleBar* getTitleBar() const = 0;

    void makeConnections();

    QWidget* containerWidget_;

private:
    void setProperties();      

    int maxWidth_;
    int maxHeight_;
};

#endif // BASEWINDOW_H
