#include "roiCv.h"
#include <QDebug>

roiCv::roiCv(){

}
roiCv::roiCv(ImagenCv *original, ImagenCv *interes){

}

IplImage* roiCv::getSubImg(IplImage *original, IplImage *interes, int x, int y, int width, int height){

     cvSetImageROI(original, cvRect(x,y,width,height));
     interes  = cvCreateImage(cvGetSize(original), original->depth, original->nChannels);
     cvCopy(original, interes, NULL);
     cvResetImageROI(original);

     return interes;

}

IplImage* roiCv::getSubImg(ImagenCv *original, ImagenCv *interes, int x, int y, int width, int height){
     IplImage* subimagen =NULL;
     subimagen=getSubImg(original->obtenerImagen(),interes->obtenerImagen(),x,y,width,height);
     return subimagen;
}
