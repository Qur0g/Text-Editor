#include "tab.h"

Tab::Tab(QWidget* parent, QString name)
    : QWidget{parent}, m_name(name)
{
    m_mainLayout = new QHBoxLayout(this);
}
