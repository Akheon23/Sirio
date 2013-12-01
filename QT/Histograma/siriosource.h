#ifndef SIRIOSOURCE_H
#define SIRIOSOURCE_H

#include <QMainWindow>
#include <highgui.h>
#include <cv.h>
#include "Imagen/imagenCv.h"
#include "Imagen/imagenQt.h"
#include "Imagen/handler.h"
#include "Imagen/smatch.h"
#include "Imagen/sbss.h"
namespace Ui {
class SirioSource;
}

class SirioSource : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SirioSource(QWidget *parent = 0);
    ~SirioSource();
    
    IplImage* src;
    IplImage* src2;
    IplImage* src3;
    IplImage* src4;
    IplImage* resultado;
    IplImage* resultadocolor;
    handler Cannis;
    sMatch  Halley;
    sBss    perseid;
    CvHistogram* hist;
    CvHistogram* hist2;
    float emdresult;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SirioSource *ui;
};

#endif // SIRIOSOURCE_H
