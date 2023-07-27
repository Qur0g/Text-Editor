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
    QVBoxLayout* layout_;

    TitleBar* titleBar_;

    QWidget* content_;

    struct Content_
    {
        QWidget* content;

        enum class Type
        {
            Home,
            New,
            Open
        };
    };


};

#endif // MAINWIDGET_H
