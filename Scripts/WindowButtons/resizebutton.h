#ifndef RESIZEBUTTON_H
#define RESIZEBUTTON_H

#include "windowbutton.h"

class TitleBar;

class ResizeButton : public WindowButton
{
    Q_OBJECT
public:
    ResizeButton(TitleBar* parent = nullptr);

private slots:
    void toggleIcon();

private:
    const QString m_maximizedIconPath = ":/icons/resize.png";
    const QString m_noStateIconPath = ":/icons/resize2.png";
};

#endif // RESIZEBUTTON_H
