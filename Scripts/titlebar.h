#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

class WindowButton;
class ResizeButton;

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    TitleBar(QWidget *parent = nullptr);

    void createWindowButtons();
    void setTitle(QString title);

    WindowButton* m_minimizeButton;
    ResizeButton* m_resizeButton;
    WindowButton* m_closeButton;

signals:
    void moveWindow();
    void resizeWindow(QMouseEvent*);

protected:
    void dragEnterEvent(QDragEnterEvent*) override;
    void dragMoveEvent(QDragMoveEvent*) override;

    void dropEvent(QDropEvent*) override;
    void resizeEvent(QResizeEvent*) override;

    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseDoubleClickEvent(QMouseEvent*) override;

    QHBoxLayout* m_mainLayout;

private:
    void setProperties();

    QHBoxLayout* m_windowButtonsLayout;
    QVector<WindowButton*> m_windowButtons;

    QLabel* m_title = nullptr;

    bool isDragging = false;
};

#endif // HEADBAR_H

