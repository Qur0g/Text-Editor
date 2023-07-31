#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

class TitleBar;
class HomeContent;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout* layout_;

    TitleBar* titleBar_;

    HomeContent* content_;

    /*struct Content
    {
        enum class Type
        {
            Home,
            New,
            Open
        };

        QWidget* content;
        Type type;
    };*/
};

#endif // MAINWIDGET_H
