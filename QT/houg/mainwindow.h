#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>

#include <stdio.h>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <integralproy.h>
#include <fourier.h>
#include <simage.h>
#include <linearregretion.h>
#include<hog.hpp>
//#include <octave/oct.h>
//#include <octave/octave.h>
//#include <octave/parse.h>
//#include </home/lex/OpenCV-2.4.2/modules/nonfree/include/opencv2/nonfree/nonfree.hpp>
//#include <opencv2/legacy/legacy.hpp>
//#include "Scountour/scontour.h"
//#include "Simage/simage.h"

#include<iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define PI 3,141516;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    IntegralProy integral;
    Fourier f;



private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
