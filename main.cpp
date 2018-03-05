#include "whiteboard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Whiteboard w;
    w.show();

    return a.exec();
}
