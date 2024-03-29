#include "smatch.h"

sMatch::sMatch()
{
}

/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: obtiene el reconocimiento supervisado de una imagen

***************************************************************************************************/


IplImage* sMatch::MatchT(IplImage *source, IplImage *patch)
{
    IplImage*  resultado=cvCreateImage(cvSize( source->width - patch->width +1, source->height - patch->height +1),IPL_DEPTH_32F,1);
    cvMatchTemplate(source,patch,resultado,CV_TM_CCOEFF_NORMED);
    return resultado;
}

/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: obtiene la proyeccion de fondo de una imagen

***************************************************************************************************/


IplImage *sMatch::sHistMatch(IplImage *patch, IplImage *source)
{
    //-----------------Creo imagenes a usar----------------------//
    //crea imagen en HSV
    IplImage* hsv=cvCreateImage( cvGetSize(source),8,3);

    //cambia imagen a HSV
    cvCvtColor( source, hsv, CV_BGR2HSV);

    //crea imagenes paraalmacenar cada canal del HSV
    IplImage* h_plane=cvCreateImage( cvGetSize(source),8,1);
    IplImage* s_plane=cvCreateImage( cvGetSize(source),8,1);
    IplImage* v_plane=cvCreateImage( cvGetSize(source),8,1);
    IplImage* planes[] = {h_plane, s_plane};

    //separa cada imagen por canales ??
    cvCvtPixToPlane( hsv, h_plane, s_plane, v_plane, 0);

    //----------------construccion del histograma-------------------------//

    //tamaño del histograma
    int h_bins=30,s_bins=32;

    CvHistogram* hist;
    {
    int hist_size[]={h_bins, s_bins}; //tamaño del histograma
    float h_ranges[]={0,180}; //numero de contenedores para canal H
    float s_ranges[]={0,255}; //numero de contenedores para canal S
    float* ranges[]= {h_ranges, s_ranges}; //se configura para un histograma uniforme o no,en este caso uniforme

    //inicializacion del histograma
    hist= cvCreateHist(2,
    hist_size,
    CV_HIST_ARRAY,
    ranges,
    1);//indica que el histograma es uniforme si >0
    }

    //---------------------calculo del histograma-------------------------//
    //int i=0;
    cvCalcHist( planes, hist, 0, 0 ); //calcula el histograma
    //cvNormalizeHist( &hist[i], 1.0); //normaliza el histograma

    //--------------------preparo la proyeccion de fondo--------------------//


    IplImage* hsv2=cvCreateImage( cvGetSize(patch),8,3);
    //cambia imagen a HSV
    cvCvtColor( patch, hsv2, CV_BGR2HSV);
    //creo la imagenes para alojar cada canal de la imagen a comparar
    IplImage* h1_plane=cvCreateImage( cvGetSize(patch),8,1);
    IplImage* s1_plane=cvCreateImage( cvGetSize(patch),8,1);
    IplImage* v1_plane=cvCreateImage( cvGetSize(patch),8,1);


    cvCvtPixToPlane( hsv2, h1_plane, s1_plane, v1_plane, 0);
    IplImage* planes1[] = {h1_plane, s1_plane};

    //imagen para mostrar el back projection
    IplImage* back=cvCreateImage( cvGetSize(patch),8,1);

    //calculo el Back projection

    cvCalcBackProject(planes1,back,hist);

    cvReleaseImage(&hsv);
    cvReleaseImage(&hsv2);
    cvReleaseImage(&h_plane);
    cvReleaseImage(&s_plane);
    cvReleaseImage(&v_plane);
    cvReleaseImage(&h1_plane);
    cvReleaseImage(&s1_plane);
    cvReleaseImage(&v1_plane);
    //cvReleaseImage(img[0] );


    return back;
}

/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: obtiene la proyeccion de fondo con parche de una imagen, src es la imagen que buscare
en src2
***************************************************************************************************/

IplImage *sMatch::sHistPathMatch(IplImage *src2, IplImage *src)
{
    int x = 500;
    int y = 380;
    int width = 300;
    int height = 200;

    //-----------------Creo imagenes a usar----------------------//
    //crea imagen en HSV
    IplImage* hsv=cvCreateImage( cvGetSize(src),8,3);

    //cambia imagen a HSV
    cvCvtColor( src, hsv, CV_BGR2HSV);


    //crea imagenes paraalmacenar cada canal del HSV
    IplImage* h_plane=cvCreateImage( cvGetSize(src),8,1);
    IplImage* s_plane=cvCreateImage( cvGetSize(src),8,1);
    IplImage* v_plane=cvCreateImage( cvGetSize(src),8,1);
    IplImage* planes[] = {h_plane, s_plane};

    //separa cada imagen por canales ??
    cvCvtPixToPlane( hsv, h_plane, s_plane, v_plane, 0);

    //----------------construccion del histograma-------------------------//

    //tamaño del histograma
    int h_bins=30,s_bins=32;

    CvHistogram* hist;
    {
    int hist_size[]={h_bins, s_bins}; //tamaño del histograma
    float h_ranges[]={0,180}; //numero de contenedores para canal H
    float s_ranges[]={0,255}; //numero de contenedores para canal S
    float* ranges[]= {h_ranges, s_ranges}; //se configura para un histograma uniforme o no,en este caso uniforme

    //inicializacion del histogramasrc2
    hist= cvCreateHist(2,
    hist_size,
    CV_HIST_ARRAY,
    ranges,
    1);//indica que el histograma es uniforme si >0
    }

    //---------------------calculo del histograma-------------------------//
    int i=0;
    cvCalcHist( planes, hist, 0, 0 ); //calcula el histograma
    //cvNormalizeHist( &hist[i], 1.0); //normaliza el histograma

    //--------------------preparo la proyeccion de fondo--------------------//

    //IplImage* src2=cvLoadImage( "/home/lex/Cv/Images/video_screenshot_21.07.2013.png",1);
    //cvSetImageROI(src2, cvRect(x,y,width,height));
    IplImage* hsv2=cvCreateImage( cvGetSize(src2),8,3);
    //cambia imagen a HSV
    cvCvtColor( src2, hsv2, CV_BGR2HSV);
    //creo la imagenes para alojar cada canal de la imagen a comparar
    IplImage* h1_plane=cvCreateImage( cvGetSize(src2),8,1);
    IplImage* s1_plane=cvCreateImage( cvGetSize(src2),8,1);
    IplImage* v1_plane=cvCreateImage( cvGetSize(src2),8,1);


    cvCvtPixToPlane( hsv2, h1_plane, s1_plane, v1_plane, 0);
    IplImage* planes1[] = {h1_plane, s1_plane};

    //se crea el patch que se deslizara por la pantalla
    cv::Size patch(src->width,src->height);

    //imagen para mostrar el resultado
    IplImage* dst=cvCreateImage( cvSize(planes1[0][0].width - patch.width +1,planes1[0][0].height - patch.height +1),32,1);

    //calculo el Back projection

    cvCalcBackProjectPatch(planes1, dst, patch, hist, CV_COMP_CORREL, 1);

    /*metodos de comparacion
    CV_COMP_CORREL
    CV_COMP_CHISQR
    CV_COMP_INTERSECT
    CV_COMP_BHATTACHARYYA
    */

    cvReleaseImage(&hsv);
    cvReleaseImage(&hsv2);
    cvReleaseImage(&h_plane);
    cvReleaseImage(&s_plane);
    cvReleaseImage(&v_plane);
    cvReleaseImage(&h1_plane);
    cvReleaseImage(&s1_plane);
    cvReleaseImage(&v1_plane);
    //cvReleaseImage(&planes1[1]); pendiente liberacion de arreglos

    return dst;
}
