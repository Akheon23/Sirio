#include <QtGui/QApplication>
#include "process.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Process w;
    w.show();
    
    return a.exec();
}
