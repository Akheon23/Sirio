#include <QApplication>
#include "segmentationint.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SegmentationINT w;
    w.show();
    
    return a.exec();
}
