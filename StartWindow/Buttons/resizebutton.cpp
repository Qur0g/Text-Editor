#include "resizebutton.h"
#include "StartWindow/titlebar.h"

ResizeButton::ResizeButton(TitleBar* parent)
    : WindowButton(parent, ":/icons/resize2.png")
{
    connect(this, &ResizeButton::clicked, this, &ResizeButton::toggleIcon);
    connect(parent, &TitleBar::moveWindow, this, &ResizeButton::toggleIcon);
}

void ResizeButton::toggleIcon()
{
    if(qobject_cast<TitleBar*>(sender()))
    {
        if(iconPath_ == noStateIconPath_)
        {
            setIcon(QIcon(maximizedIconPath_));
            iconPath_ = maximizedIconPath_;
        }
    }
    else
    {
        if(iconPath_ == maximizedIconPath_)
        {
            setIcon(QIcon(noStateIconPath_));
            iconPath_ = noStateIconPath_;
        }
        else
        {
            setIcon(QIcon(maximizedIconPath_));
            iconPath_ = maximizedIconPath_;
        }
    }
}
