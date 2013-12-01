#ifndef IMAGENQT_H
#define IMAGENQT_H

#include <qimage.h>
#include <qlabel.h>
#include "imagenCv.h"


class ImagenQt
{
public:

    /******************************************************************************************
    Constructores
    ******************************************************************************************/
    ImagenQt();
    ImagenQt(IplImage* pImagen);
    ImagenQt(ImagenCv* pImagen);


    /******************************************************************************************
    Conversiones
    ******************************************************************************************/
    void convertirImagen(IplImage* pImagen);//Futuro uso
    void convertirImagen(ImagenCv* pImagen);
    void convertirImagenGris(ImagenCv* pImagen);

    void convertirImagenAGris(ImagenCv* pImagen);//agregada por sebastian

    /******************************************************************************************
    Salidas
    ******************************************************************************************/
    void mostrarImagen(const char* pVentana, QWidget* pInterfaz);
    void mostrarImagen(const char* pVentana, QWidget* pInterfaz, int pAncho, int pAlto);


    /******************************************************************************************
    Getters
    ******************************************************************************************/
    QImage obtenerImagenQT();

private:

    QImage imagenQt;
    QLabel *objeto;

    ImagenCv imagenRGB;

};

#endif // IMAGENQT_H
