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

    QString m_iconPath;
    const int m_width = 50;
};

#endif // WINDOWBUTTON_H
