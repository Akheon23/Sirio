#ifndef SMATCH_H
#define SMATCH_H
#include "imagenCv.h"
#include "imagenQt.h"
#include "cxcore.h"


class sMatch
{
public:
    sMatch();


    IplImage* MatchT(IplImage* source,IplImage* patch);
    IplImage* sHistMatch(IplImage* patch,IplImage* source);
    IplImage* sHistPathMatch(IplImage*src2,IplImage* src);

};

#endif // SMATCH_H
