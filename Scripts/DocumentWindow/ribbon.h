#ifndef RIBBON_H
#define RIBBON_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTabWidget>

class Tab;

class Ribbon : public QWidget
{
    Q_OBJECT
public:
    explicit Ribbon(QWidget *parent = nullptr);

signals:
    void pasteButtonClicked();
    void cutButtonClicked();
    void copyButtonClicked();
    void undoButtonClicked();
    void redoButtonClicked();
    void formatButtonClicked();

private:
    Tab* m_activeTab = nullptr;

    //Tab* createTab(QString);

    //QHBoxLayout* m_navigationLayout;

    //QTabWidget* tabWidget;
};

#endif // RIBBON_H
