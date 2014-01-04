#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include </home/lex/OpenCV-2.4.2/modules/nonfree/include/opencv2/nonfree/nonfree.hpp>
#include <opencv2/legacy/legacy.hpp>
#include"hog.hpp"
#include"Ssobel.hpp"
#include"scontour.h"
#include"integralproy.h"
#include"simage.h"

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
