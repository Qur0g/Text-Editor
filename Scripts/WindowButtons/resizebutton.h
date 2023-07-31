#ifndef RESIZEBUTTON_H
#define RESIZEBUTTON_H

#include "windowbutton.h"

class TitleBar;

class ResizeButton : public WindowButton
{
    Q_OBJECT
public:
    ResizeButton(TitleBar *parent = nullptr);

private slots:
    void toggleIcon();

private:  
    QString maximizedIconPath_ = ":/icons/resize.png";
    QString noStateIconPath_ = ":/icons/resize2.png";
};

#endif // RESIZEBUTTON_H
