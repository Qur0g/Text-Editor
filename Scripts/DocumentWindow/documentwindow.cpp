#include "documentwindow.h"
#include "Scripts/titlebar.h"

DocumentWindow::DocumentWindow(QWidget *parent)
    : BaseWindow{parent}
{
    buildUI();
}

void DocumentWindow::buildUI()
{

}

TitleBar* DocumentWindow::getTitleBar() const
{
    return titleBar_;
}




