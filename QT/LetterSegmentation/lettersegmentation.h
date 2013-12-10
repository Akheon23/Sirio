#ifndef LETTERSEGMENTATION_H
#define LETTERSEGMENTATION_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include "Scountour/scontour.h"
#include "segmentation.h"
#include <qdebug.h>

using namespace cv;
using namespace std;



namespace Ui {
class LetterSegmentation;
}

class LetterSegmentation : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit LetterSegmentation(QWidget *parent = 0);
    ~LetterSegmentation();


    Segmentation extractor;
    Scontour handler;
    vector<vector<Point> > cmuestra;//contornos muestra
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LetterSegmentation *ui;
};

#endif // LETTERSEGMENTATION_H
