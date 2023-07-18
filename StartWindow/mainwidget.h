#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

class TitleBar;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout* layout;

    TitleBar* titleBar;
};

#endif // MAINWIDGET_H
