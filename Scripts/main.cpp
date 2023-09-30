#include "StartWindow/startwindow.h"
#include "DocumentWindow/documentwindow.h"
//#include "qscreen.h"

#include <QApplication>

#include <QLabel>
#include <QScrollArea>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //StartWindow startWindow;
    //startWindow.show();

    DocumentWindow documentWindow;
    documentWindow.show();

    return a.exec();
}
