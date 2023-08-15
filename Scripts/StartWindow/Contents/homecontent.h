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
    QWidget* m_topWidget;
    QWidget* m_bottomWidget;

    //QList<Template> templates_;

};

#endif // HOMECONTENT_H
