#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include "simage.h"
#include <QDebug>

#include "videoprocessor.h"
#include "featuretracker.h"
#include "frameprocessor.h"
#include "surfd.h"
#include "Smatch/hog.h"
#include "Scountour/scontour.h"
#include "/home/lex/Cv/QT/Libs/SvideoProcessor/integralproy.h"



using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    Scontour handler;
    vector<vector<Point> > cmuestra;//contornos muestra

    void Mostrar(cv::Mat PlacaMostrar2);

    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
