#include <QApplication>
#include "extraercontornos.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExtraerContornos w;
    w.show();
    
    return a.exec();
}
