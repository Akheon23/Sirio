#include <QtGui/QApplication>
#include "detector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Detector w;
    w.show();
    
    return a.exec();
}
