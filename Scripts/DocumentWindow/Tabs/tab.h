#ifndef TAB_H
#define TAB_H

#include <QWidget>
#include <QHBoxLayout>

class Tab : public QWidget
{
    Q_OBJECT
public:
    Tab(QWidget* parent = nullptr, QString name = "");

    virtual void displayContent() = 0;
    virtual void hideContent() = 0;

protected:
    QString m_name;
    QHBoxLayout* m_mainLayout;

signals:

private:


};

#endif // TAB_H
