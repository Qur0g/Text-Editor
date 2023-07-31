#ifndef HOMECONTENT_H
#define HOMECONTENT_H

#include <QWidget>

class Template;

class HomeContent : public QWidget
{
    Q_OBJECT
public:
    explicit HomeContent(QWidget *parent = nullptr);

signals:

private:
    QWidget* topWidget_;
    QWidget* bottomWidget_;

    //QList<Template> templates_;

};

#endif // HOMECONTENT_H
