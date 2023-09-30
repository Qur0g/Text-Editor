#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class TitleBar;
class HomeContent;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

signals:

private:
    TitleBar* m_titleBar;

    HomeContent* m_content;

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
