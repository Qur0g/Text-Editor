#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVector>

class Menu : public QWidget
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);

signals:

private slots:

private:
    void createButtons();
    QPushButton* createButton(QString name, QKeySequence shortcut);
    //void connectButtons();

    QVBoxLayout* m_menuLayout;

    //QVector<QPushButton*> buttons;
    QPushButton* m_homeButton;
    QPushButton* m_newButton;
    QPushButton* m_openButton;
};

#endif // MENU_H
