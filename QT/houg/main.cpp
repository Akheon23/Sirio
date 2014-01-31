#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    // Argumentos para octave
//        argv[0] = "GUI_NS";
//        argv[1] = "-q"; // Iniciar en modo silencioso (no muestra informacion de la version o la licencia

//        argc = 2; // Numero de argumentos
//        setlocale(LC_ALL, "en_US.UTF-8"); // Indicar a octave que se trabajara en English, o si no, no funciona
//        octave_main (argc, argv, true); // Llamar al main de octave


    ///////////////////////////////////////////////////////////////////////
    
    return a.exec();
}
