#ifndef HANDLER_H
#define HANDLER_H

#include "imagenCv.h"
#include "imagenQt.h"
#include "/home/lex/OpenCV-2.4.2/include/opencv/cxcore.h"
#include "/home/lex/OpenCV-2.4.2/include/opencv/highgui.h"
//#include "/home/lex/OpenCV-2.4.2/include/opencv/cv.h"
#include "/home/lex/OpenCV-2.4.2/include/opencv2/opencv.hpp"


class handler
{
public:
    handler();
    ~handler();

    IplImage* getSubImg(IplImage* original,IplImage* interes,int x, int y, int width, int height);
    IplImage* getSubImg(ImagenCv* original,ImagenCv* interes,int x, int y, int width, int height);
    IplImage* rotate(IplImage* Ioriginal,int angulo);
    void showInLabel(IplImage* origen,const char * pVentana,QWidget *pInterfaz);
    int compare(IplImage *actual,IplImage *anterior,int umbral);
    float pixval(IplImage* Ioriginal,int x,int y,int canal);
    ImagenQt matchview(IplImage* matchresult);
    IplImage* resize(IplImage* img,int width,int height);
    void cvrect(int r, int g, int b, int grosor, IplImage* original, int x, int y , int width, int height);
    bool watchdog(IplImage* muestra, IplImage* img, float umbral);

    void showInLabel(ImagenCv origen,ImagenQt destino,const char *pVentana,QWidget *pInterfaz);
    void showInLabel(ImagenCv origen,const char *pVentana, QWidget *pInterfaz);

    int descargarWget(const char *a);

    int Sys_Time(int control, int control2);

    IplImage* matchtemplate(IplImage* Ioriginal,IplImage* Imuestra);

    //conversiones





};

#endif // HANDLER_H
