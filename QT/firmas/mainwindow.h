#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>

#include <stdio.h>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <opencv2/opencv.hpp>
//#include </home/lex/OpenCV-2.4.2/modules/nonfree/include/opencv2/nonfree/nonfree.hpp>
//#include <opencv2/legacy/legacy.hpp>
//#include "Scountour/scontour.h"
//#include "Simage/simage.h"

#include<iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void get_firma_binary_changes(cv::Mat src, int num_lines, int *src_firma);
    cv::Mat draw_firma(cv::Mat src, int num_lines);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
