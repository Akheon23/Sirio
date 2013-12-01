#ifndef TRACK_H
#define TRACK_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include "featuretracker.h"
using namespace std;
using namespace cv;

namespace Ui {
class Track;
}

class Track : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Track(QWidget *parent = 0);
    ~Track();


    //ACTUALIZACION FRAME
    QTimer* gTimer;//gTimer= Objeto qtimer para generar interrupciones con el fin de actualizar el frame
    int gTimeUpdateMS;//gTimeUpdateMS= variable entera para establecer la base de tiempo en milisegundos
    cv::VideoCapture camera;//Objeto tipo video para extraer los frames

    //IMAGENES
    Mat frame;
    Mat Output;
    Mat image;//imagen para detectar contornos
    Mat imageCopy;//crea una imagen de dimensiones 0

    //VARIABLES PARA EL MANEJO EXEPCIONES EN CONEXION
    int  delayForErrors;
    bool errorDetected;

    //Objetos
    FeatureTracker follow;

public slots:
    void refreshFrame();//funcion de actualizacion

    
private:
    Ui::Track *ui;
};

#endif // TRACK_H
