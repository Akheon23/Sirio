#ifndef SURFD_H
#define SURFD_H
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include </home/lex/OpenCV-2.4.2/modules/nonfree/include/opencv2/nonfree/nonfree.hpp>
#include <opencv2/legacy/legacy.hpp>

using namespace cv;
using namespace std;

class SurfD
{
public:
    SurfD();
    ~SurfD();


    //Extraccion de descriptores
    vector<cv::KeyPoint>  V_vectKeypoints;//para alojar puntos claves
    SurfFeatureDetector surf;//Objeto detector de caracteristicas surf
    SurfDescriptorExtractor surfDesc;//objeto tipo surf descriptor

    //Comparacion de descriptores
    cv::BruteForceMatcher<cv::L2<float> > matcher;//comparador de descriptores
    vector<cv::DMatch> matches;//alojara las comparaciones

    //Descriptores
    Mat M_vectDescriptors;//aloja los descriptores


    //Metodos

    cv::Mat getSurfDescriptors(cv::Mat M_imgSource);
};

#endif // SURFD_H
