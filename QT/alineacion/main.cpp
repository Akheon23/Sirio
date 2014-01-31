#include <QApplication>
#include "alineacion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Alineacion w;
    w.show();
    
    return a.exec();
}
