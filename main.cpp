#include "qtMouseMover.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtMouseMover w;
    w.show();
    return a.exec();
}
