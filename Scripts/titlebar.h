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

    void resizeButtonClick();

    WindowButton* minimizeButton_;
    ResizeButton* resizeButton_;
    WindowButton* closeButton_;

signals:
    void moveWindow();
    void resizeWindow(QMouseEvent* event);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *p_event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    void setProperties();
    void createButtons();

    QHBoxLayout* mainLayout_;
    QHBoxLayout* windowButtonsLayout_;
    QVBoxLayout* labelLayout_;

    QVector<WindowButton*> windowButtons_;

    QLabel* title_;
};

#endif // HEADBAR_H

