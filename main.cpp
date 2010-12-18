#include <QtGui/QApplication>
#include "yomewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    yomewidget w;
    w.show();

    return a.exec();
}
