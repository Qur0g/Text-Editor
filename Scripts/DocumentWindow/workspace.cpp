#include "workspace.h"

#include <QScreen>
#include <QGuiApplication>
#include <QDebug>
#include <QVBoxLayout>
#include <QScrollArea>

Workspace::Workspace(QWidget *parent)
    : QWidget{parent}
{
    //auto layout = new QVBoxLayout(this);

    //auto scroll = new QScrollArea(this);
    //scroll->setWidgetResizable(true);

    //auto scrollWidget = new QWidget(scroll);
    //scrollWidget->setMinimumWidth(1000);

    //auto l = new QVBoxLayout(scrollWidget);

    //scrollWidget->setLayout(l);
    //scroll->setWidget(scrollWidget);

    //this->setContentsMargins(0, 100, 0, 0);
    this->setAttribute(Qt::WA_StyledBackground);
    this->setStyleSheet("background-color: white;");
    this->setFixedWidth(816);
    this->setFixedHeight(1500);


    //scrollWidget->setAttribute(Qt::WA_StyledBackground);
    //scrollWidget->setStyleSheet("background-color: white;");
    //scrollWidget->setFixedHeight(1000);

    //qDebug() << QGuiApplication::primaryScreen()->logicalDotsPerInch();
    //this->
}
