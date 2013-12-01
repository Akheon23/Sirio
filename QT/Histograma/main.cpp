#include <QApplication>
#include "siriosource.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SirioSource w;
    w.show();
    



    return a.exec();
}
