#ifndef SEGMENTATIONINT_H
#define SEGMENTATIONINT_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <qdebug.h>
#include <integralproy.h>

namespace Ui {
class SegmentationINT;
}

class SegmentationINT : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SegmentationINT(QWidget *parent = 0);
    ~SegmentationINT();

   IntegralProy integral;


    
private slots:
    void on_pushButton_clicked();

private:
    Ui::SegmentationINT *ui;
};

#endif // SEGMENTATIONINT_H
