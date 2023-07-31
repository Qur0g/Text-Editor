#include "homecontent.h"

HomeContent::HomeContent(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_StyledBackground);
    setStyleSheet("background-color: lightgray;");
}
