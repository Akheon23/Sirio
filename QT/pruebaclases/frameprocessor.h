#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

class FrameProcessor
{
public:
    FrameProcessor();
    ~FrameProcessor();
    virtual void process(cv::Mat &input, cv::Mat &output)=0;


};

#endif // FRAMEPROCESSOR_H
