#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QTextEdit>

class Workspace : public QTextEdit
{
    Q_OBJECT
public:
    explicit Workspace(QWidget *parent = nullptr);

signals:

protected:
    void mousePressEvent(QMouseEvent*) override;

private:
    void boldText();

};

#endif // WORKSPACE_H
