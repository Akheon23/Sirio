#include "imagenQt.h"
#include <qdebug.h>

ImagenQt::ImagenQt()
{

}

ImagenQt::ImagenQt(ImagenCv* pImagen){

    cvCvtColor(pImagen->obtenerImagen(), pImagen->obtenerImagen(), CV_BGR2RGB);
    imagenQt = QImage( pImagen->obtenerInformacion(), pImagen->ancho, pImagen->alto, QImage::Format_RGB888);
}

void ImagenQt::convertirImagen(IplImage* pImagen){

    //cvCvtColor(pImagen, pImagen, CV_BGR2RGB);
    //imagenQt = QImage( pImagen->obtenerInformacion(), pImagen->ancho, pImagen->alto, QImage::Format_RGB888);
}

void ImagenQt::convertirImagen(ImagenCv* pImagen){

    cvCvtColor(pImagen->obtenerImagen(), pImagen->obtenerImagen(), CV_BGR2RGB);
    imagenQt = QImage( pImagen->obtenerInformacion(), pImagen->ancho, pImagen->alto, QImage::Format_RGB888);
}

void ImagenQt::convertirImagenAGris(ImagenCv* pImagen){

    cvCvtColor(pImagen->obtenerImagen(), pImagen->obtenerImagen(), CV_BGR2RGB);
    imagenQt = QImage( pImagen->obtenerInformacion(), pImagen->ancho, pImagen->alto, QImage::Format_Mono);

}

void ImagenQt::convertirImagenGris(ImagenCv* pImagen){

    //ImagenCv ImagenTemporal;
//    ImagenTemporal.GrisesaRGV(pImagen);
    imagenRGB.GrisesaRGV(pImagen);
    convertirImagen(&imagenRGB);
    //imagenQt = QImage( Imagentemporal->obtenerInformacion(), Imagentemporal->ancho, Imagentemporal->alto, QImage::Format_RGB888);
}

QImage ImagenQt::obtenerImagenQT(){

    return imagenQt;
}

void ImagenQt::mostrarImagen(const char* pVentana, QWidget* pInterfaz){//sebas:recibe el nombre del label donde se abrira y la interfaz a la cual pertenece el label

    objeto = qFindChild<QLabel*>(pInterfaz, pVentana);
    objeto->setPixmap( QPixmap::fromImage(imagenQt, Qt::AutoColor) );
}

void ImagenQt::mostrarImagen(const char* pVentana, QWidget* pInterfaz, int pAncho, int pAlto){

    objeto = qFindChild<QLabel*>(pInterfaz, pVentana);

    objeto->resize(pAncho, pAlto);
    objeto->setPixmap( QPixmap::fromImage(imagenQt, Qt::AutoColor) );
}

