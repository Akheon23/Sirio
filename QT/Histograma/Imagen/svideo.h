#ifndef SVIDEO_H
#define SVIDEO_H
#include <string.h>
#include "imagenCv.h"
#include "imagenQt.h"
#include "cxcore.h"

using namespace std;
using namespace cv;

class sVideo
{
public:
    sVideo();

    void setPath (String ruta);
    IplImage* getFrameVideo ();

};

#endif // SVIDEO_H
