#include "simage.h"


Simage::Simage()
{



}

Simage::~Simage()
{

}




/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Encuentra la intensidad mayor en la imagen  la coloca en inten,retorna código de error.

***************************************************************************************************/


int Simage::Pixval(cv::Mat image, int &inten)
{

    inten=0;
    int value=0;
    if(!image.data) //comprueba si la imagen se cargo correctamente
           return 0;

    for(int i=0;i< image.size().width;i++){//hasta el ancho de la imagen
            for(int j=0;j< image.size().height;j++){//hasta el alto de la imagen
                 value=image.at<uchar>(j,i);
                 if(inten < value)inten=value;

            }
        }

    return 1;


}




/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Encuentra el numero de pixeles que superan el umbral y lo comola en el entero #cambios,
retorna código de error.

***************************************************************************************************/

int Simage::Pixval(cv::Mat image, float umbral, int &ncambios)
{

    int value=0;
    if(!image.data) //comprueba si la imagen se cargo correctamente
           return 0;

    for(int i=0;i< image.size().width;i++){//hasta el ancho de la imagen
            for(int j=0;j< image.size().height;j++){//hasta el alto de la imagen
                 value=image.at<uchar>(j,i);
                 if(value > umbral)ncambios++;

            }
        }

    return 1;




}


/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Encuentra el numero de pixeles que superan el umbral y lo comola en el entero #cambios,
retorna código de error.

***************************************************************************************************/

int Simage::Pixval(cv::Mat image, int umbral, int &ncambios)
{



    int value=0;
    if(!image.data) //comprueba si la imagen se cargo correctamente
           return 0;

    for(int i=0;i< image.size().width;i++){//hasta el ancho de la imagen
            for(int j=0;j< image.size().height;j++){//hasta el alto de la imagen
                 value=image.at<uchar>(j,i);
                 if(value > umbral)ncambios++;

            }
        }

    return 1;

}
