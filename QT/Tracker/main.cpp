#include <QApplication>
#include "track.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Track w;
    w.show();
    
    return a.exec();
}
