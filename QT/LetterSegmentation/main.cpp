#include <QApplication>
#include "lettersegmentation.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LetterSegmentation w;
    w.show();
    
    return a.exec();
}
