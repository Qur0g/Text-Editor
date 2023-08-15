#include "resizebutton.h"
#include "Scripts/titlebar.h"

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
        if(m_iconPath == m_noStateIconPath)
        {
            setIcon(QIcon(m_maximizedIconPath));
            m_iconPath = m_maximizedIconPath;
        }
    }
    else
    {
        if(m_iconPath == m_maximizedIconPath)
        {
            setIcon(QIcon(m_noStateIconPath));
            m_iconPath = m_noStateIconPath;
        }
        else
        {
            setIcon(QIcon(m_maximizedIconPath));
            m_iconPath = m_maximizedIconPath;
        }
    }
}
