#include "handler.h"
#include <time.h>

handler::handler()
{       
}

handler::~handler()
{
}

/**************************************************************************************************
Funciones
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion:(retorna apuntador IplImage con la imagen de interes )
***************************************************************************************************/

IplImage* handler::getSubImg(IplImage *original, IplImage *interes, int x, int y, int width, int height){

     cvSetImageROI(original, cvRect(x,y,width,height));
     interes  = cvCreateImage(cvGetSize(original), original->depth, original->nChannels);
     cvCopy(original, interes, NULL);
     cvResetImageROI(original);

     cvRectangle(original,cvPoint(x,y),cvPoint(x + width,y + height),CV_RGB(250,0,0),7,8);


     return interes;
}
/**************************************************************************************************
Funciones
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion:(retorna apuntador IplImage con la imagen de interes )

***************************************************************************************************/
IplImage* handler::getSubImg(ImagenCv *original, ImagenCv *interes, int x, int y, int width, int height){
     IplImage* subimagen =NULL;
     subimagen=getSubImg(original->obtenerImagen(),interes->obtenerImagen(),x,y,width,height);

     return subimagen;
}
/**************************************************************************************************
Funciones
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion:(retorna un valor entero indicando si la hora actual esta en el rango entre dos horas, 1 si esta en el rango
             -1 si ocurrio un error, 0 si esta por fuera del rango)

***************************************************************************************************/

int handler::Sys_Time(int control, int control2)
{
    time_t current_time;//sospecha
            char* c_time_string;
           current_time = time(NULL);

          if (current_time == ((time_t)-1))
           {
              return -1;
           }
           c_time_string = ctime(&current_time);
           if (c_time_string == NULL)
           {
               return -1;
           }

           int Sistem_Time;
           Sistem_Time=(c_time_string[11]-48)*1000+(c_time_string[12]-48)*100+(c_time_string[14]-48)*10+c_time_string[15]-48;

          if(Sistem_Time <= control || Sistem_Time >= control2)
          {
            return 0;
        }
          else if(Sistem_Time >= control && Sistem_Time <= control2)
          {
            return 1;
        }
        return 0;

 }

/***************************************************************************************************
Funciones
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion:

****************************************************************************************************/
void handler::showInLabel(IplImage* origen,const char * pVentana,QWidget *pInterfaz)
{
    ImagenCv origen1(origen);
    ImagenQt destino;
    destino.convertirImagen(&origen1);
    destino.mostrarImagen(pVentana,pInterfaz);
    origen1.~ImagenCv();


}

/***************************************************************************************************
Funciones
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion:

****************************************************************************************************/
void handler::showInLabel(ImagenCv origen, ImagenQt destino,const char * pVentana,QWidget *pInterfaz)
{
    destino.convertirImagen(&origen);
    destino.mostrarImagen(pVentana,pInterfaz);
}

/***************************************************************************************************
Funciones
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion:

****************************************************************************************************/
void handler::showInLabel(ImagenCv origen, const char *pVentana, QWidget *pInterfaz)
{
    ImagenQt destino;
    destino.convertirImagen(&origen);
    destino.mostrarImagen(pVentana,pInterfaz);
}
/***************************************************************************************************
Funciones
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion:

****************************************************************************************************/
int handler::descargarWget(const char * a)
{
    try
    {
        int error=system(a);
        throw error;
    }
    catch(int error)
    {
        //qDebug()<<"error: "<<error;
        if(error==1024)
        return error;
        return error;
    }

}

/***************************************************************************************************
Funciones
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: obtiene el reconocimiento supervisado de una imagen

***************************************************************************************************/

IplImage* handler::matchtemplate (IplImage* Ioriginal,IplImage* Imuestra){

    IplImage*  resultado=cvCreateImage(cvSize( Ioriginal->width - Imuestra->width +1, Ioriginal->height - Imuestra->height +1),IPL_DEPTH_32F,1);
    cvMatchTemplate(Ioriginal,Imuestra,resultado,CV_TM_CCOEFF_NORMED);
    return resultado;

}

/***************************************************************************************************
Funciones
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Rota la imagen el numero de grados deseado

***************************************************************************************************/

IplImage *handler::rotate(IplImage *Ioriginal, int angulo)
{
   // IplImage *imageRotated1 = cvCloneImage(Ioriginal);
            IplImage * imageRotated1 = cvCreateImage(cvSize(Ioriginal->width,Ioriginal->height),Ioriginal->depth,Ioriginal->nChannels);
            cvCopy(Ioriginal,imageRotated1);
            //se crea una matriz para alojar la rotaicon
            CvMat* rot_mat = cvCreateMat(2,3,CV_32FC1);

            // se halla el centro para rotar la matriz
            CvPoint2D32f center = cvPoint2D32f( cvGetSize(imageRotated1).width/2, cvGetSize(imageRotated1).height/2 );
            cv2DRotationMatrix( center, angulo, 1, rot_mat );

            // transformacion
            cvWarpAffine(Ioriginal, imageRotated1, rot_mat );
            cvReleaseMat(&rot_mat);
            return   imageRotated1;

}




/***************************************************************************************************
Funciones
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: obtiene la intensidad de un pixel en la posicion indicada

***************************************************************************************************/
float handler::pixval(IplImage* Ioriginal, int x, int y,int channel)
{
    float valor;
    CvScalar intensidad;
    intensidad = cvGet2D(Ioriginal,x, y);
    valor = intensidad.val[channel] ;
    return valor;

}



/***************************************************************************************************
Funciones
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion:Resta las 2 imagenes de entrada,recorre la imagen y retorna numero de pixeles que cambiaron
de acuerdo al umbral entrado.

****************************************************************************************************/

int handler::compare(IplImage *actual, IplImage *anterior, int umbral)
{
    int i=0;
    int j=0;
    IplImage* aux;
    aux=cvCreateImage(cvGetSize(actual),IPL_DEPTH_8U, actual->nChannels);
    float intensidadpix;
    int  contador=0;
    CvScalar intensidad;
    cvSub(actual,anterior,aux);


     while (i<(aux->width)){

         while(j<(aux->height)){
            intensidad = cvGet2D(aux,j, i);
            intensidadpix = intensidad.val[0] ;
             if(intensidadpix>umbral){
                  contador++;
             }

             j++;
            }
     j=0;
     i++;
     }
     cvReleaseImage(&aux);
     return contador;
}

/***************************************************************************************************
Funciones
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion:retorna una imagen Qt que es la conversion de una Iplimage de flotantes con 32F de
profundidad

****************************************************************************************************/

ImagenQt handler::matchview(IplImage *matchresult)
{
    float valor=0;
    CvScalar intensidad;
    CvScalar intensidad1;

    int i=0;
    int j=0;
    IplImage* image_8u1;
    ImagenCv imgcv;
    ImagenQt imgqt;
    IplImage* resultado;
    image_8u1=cvCreateImage(cvSize(matchresult->width ,matchresult->height),IPL_DEPTH_8U, 1);
    while (i<(matchresult->width)){
        while(j<(matchresult->height)){
            intensidad = cvGet2D(matchresult,j, i);
             valor = intensidad.val[0] ;
            if(valor<1){
                valor=valor*255;
                intensidad1.val[0] =valor;
                cvSet2D(matchresult, j, i,intensidad1);
            }

            j++;
           }
    j=0;
    i++;
    }
    cvCvtScale(resultado,image_8u1);
    imgcv.establecerImagen(image_8u1);
    imgqt.convertirImagenGris(&imgcv);
    return imgqt;
}

/***************************************************************************************************
Funciones
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion:retorna una IplImage con el tamaño ingresado
****************************************************************************************************/

IplImage* handler::resize(IplImage *img, int width, int height)
{
    IplImage* actual=cvCreateImage(cvSize(width,height),IPL_DEPTH_8U,img->nChannels);
    cvResize(img,actual,CV_INTER_CUBIC);
    return actual;

}

void handler::cvrect(int r, int g, int b, int grosor, IplImage* original, int x, int y , int width, int height)
{
    cvRectangle(original,cvPoint(x,y),cvPoint(x + width,y + height),CV_RGB(r,g,b),grosor,8);
}


/***************************************************************************************************
Funciones
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion:devuelve 1 si la imagen de muestra se encuentra en la original o 0 en caso contrario, la
imagen de muestra debe ser mas pequeña que la original
****************************************************************************************************/

bool handler::watchdog(IplImage *muestra, IplImage *img,float umbral)
{
    //realizamos el MatchTemplate
    IplImage*  resultado=cvCreateImage(cvSize( img->width - muestra->width +1, img->height - muestra->height +1),IPL_DEPTH_32F,1);
    cvMatchTemplate(img,muestra,resultado,CV_TM_CCOEFF_NORMED);


    //buscamos puntos brillantes en la imagen
    int i=0;int j=0; float valor; CvScalar intensidad;bool find=0;
    while(i<resultado->width){
        while(j<resultado->height){
            intensidad = cvGet2D(resultado,j, i);
            valor = intensidad.val[0] ;

        if(valor>umbral){
            find=1;
        }
         j++;
        }
        i++;
        j=0;
        }
    if(find==1) return 1;
    if(find==0) return 0;


    }


