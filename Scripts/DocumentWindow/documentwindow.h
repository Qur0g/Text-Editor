#ifndef DOCUMENTWINDOW_H
#define DOCUMENTWINDOW_H

#include "Scripts/basewindow.h"

#include <QMainWindow>
#include <QVBoxLayout>

class TitleBar;
class EditTitleBar;

class DocumentWindow : public BaseWindow
{
    Q_OBJECT
public:
    explicit DocumentWindow(QWidget *parent = nullptr);

signals:

private:
    void buildUI() final;
    TitleBar* getTitleBar() const final;

    QVBoxLayout* m_mainLayout;
    EditTitleBar* m_titleBar;
};

#endif // DOCUMENTWINDOW_H
