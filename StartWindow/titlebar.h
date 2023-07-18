/*#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);

signals:

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QWidget *m_parent;
    QPoint m_pCursor;
};

#endif // TITLEBAR_H*/

#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QPushButton>
#include <QHBoxLayout>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    TitleBar(QWidget *parent = nullptr);

    QAction * addToolButton(QAction *action);

    //bool event(QEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *p_event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent* event) override;

    QPushButton* minimizeButton;
    QPushButton* resizeButton;   
    QPushButton* closeButton;

signals:
    void moveWindow();
    void resizeWindow(QMouseEvent* event);

private:
    void setProperties();
    void createButtons();

    QHBoxLayout* titleBarLayout;
};

#endif // HEADBAR_H

