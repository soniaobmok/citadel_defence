#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    QTimer::singleShot(60000, &w, SLOT(victory()));

    return a.exec();
}
