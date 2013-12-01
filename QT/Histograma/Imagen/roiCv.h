#ifndef ROICV_H
#define ROICV_H

#include "imagenCv.h"

class roiCv{

public:
    roiCv();
    roiCv(ImagenCv* original,ImagenCv* interes);

    IplImage* getSubImg(IplImage* original,IplImage* interes,int x, int y, int width, int height);
    IplImage* getSubImg(ImagenCv* original,ImagenCv* interes,int x, int y, int width, int height);

private:
    //ImagenCv imgOriginal;
    //ImagenCv regionInteres;


};


#endif // ROICV_H
