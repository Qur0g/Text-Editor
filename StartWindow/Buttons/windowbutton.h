#ifndef WINDOWBUTTON_H
#define WINDOWBUTTON_H

#include <QPushButton>
#include <QMap>

class TitleBar;

class WindowButton : public QPushButton
{
    Q_OBJECT
public:
    WindowButton(QWidget *parent = nullptr, QString iconPath = "");

signals:
    void resizeWindowRequest(QMouseEvent* event);

protected:
    bool event(QEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

    void setProperties();

    QString iconPath_;
    const int width_ = 50;
    const int height_ = 25;

private: 

};

#endif // WINDOWBUTTON_H
