//#include "widget.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel *hello = new QLabel("hello crytal", 0);
    hello->show();
//    Widget w;
//    w.show();
    return a.exec();
}
