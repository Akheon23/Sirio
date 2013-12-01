#include <QApplication>
#include "featureextractor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FeatureExtractor w;
    w.show();
    
    return a.exec();
}
