#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include "Scountour/scontour.h"
#include <qdebug.h>



using namespace cv;
using namespace std;


class Segmentation
{
public:
    Segmentation();


    Scontour handler;
    vector<vector<Point> > cmuestra;//contornos muestra
    Vector<cv::Mat> Letras;//donde estan contenidas las letras
    cv::Mat placaCorregida;

    void GetLetters(cv::Mat source);
};

#endif // SEGMENTATION_H
