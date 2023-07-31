#ifndef DOCUMENTWINDOW_H
#define DOCUMENTWINDOW_H

#include <QMainWindow>
#include <Scripts/basewindow.h>

class TitleBar;

class DocumentWindow : public BaseWindow
{
    Q_OBJECT
public:
    explicit DocumentWindow(QWidget *parent = nullptr);

signals:

private:
    void buildUI() final;
    TitleBar* getTitleBar() const final;

    TitleBar* titleBar_;
};

#endif // DOCUMENTWINDOW_H
