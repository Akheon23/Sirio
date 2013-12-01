#ifndef SIMAGE_H
#define SIMAGE_H

#include "Simage_global.h"
#include <opencv2/opencv.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <QDebug>

class SIMAGESHARED_EXPORT Simage
{
public:
    Simage();
    ~Simage();

    int Pixval(cv::Mat image, int  &inten);
    int Pixval(cv::Mat image,  float umbral, int &ncambios);
    int Pixval(cv::Mat image,  int umbral, int &ncambios);


};

#endif // SIMAGE_H
