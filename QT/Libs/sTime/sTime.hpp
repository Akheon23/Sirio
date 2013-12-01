#include<opencv2/opencv.hpp>

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include<cstdlib>
#include<QString>

#include "opencv2/opencv.hpp"


using namespace std;
using namespace cv;

class sTime
{	

public:
    sTime();
    ~sTime();
	char day[3], month[3],datevect[2],*weekday;
	int date,hour,year,triggertime,intmonth;
	bool sGetDate();
	int sGetTime();
	bool sTimeTrigger(int period, bool new_base);
	bool sSaveImage(IplImage*Image, unsigned long long index, char *path);
    QString sQSetPath(QString &a);
};
