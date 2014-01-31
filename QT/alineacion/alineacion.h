#ifndef ALINEACION_H
#define ALINEACION_H

#include <QMainWindow>
#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <simage.h>
#include <opencv2/opencv.hpp>
#include <qdebug.h>
#include <fourier.h>
#include <linearregretion.h>
using namespace cv;
using namespace std;

namespace Ui {
class Alineacion;
}

class Alineacion : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Alineacion(QWidget *parent = 0);
    ~Alineacion();
    
    Fourier f;


private slots:
    void on_pushButton_clicked();

private:
    Ui::Alineacion *ui;
};

#endif // ALINEACION_H
