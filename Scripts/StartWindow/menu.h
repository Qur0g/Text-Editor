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

    QVBoxLayout* menuLayout_;

    //QVector<QPushButton*> buttons;
    QPushButton* homeButton_;
    QPushButton* newButton_;
    QPushButton* openButton_;
};

#endif // MENU_H