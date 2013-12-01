/*
ALGORITMO EXTRACCION DE CARACTETRISTICAS

1.










*/
#ifndef FEATUREEXTRACTOR_H
#define FEATUREEXTRACTOR_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include </home/lex/OpenCV-2.4.2/modules/nonfree/include/opencv2/nonfree/nonfree.hpp>
#include <opencv2/legacy/legacy.hpp>

namespace Ui {
class FeatureExtractor;
}

class FeatureExtractor : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FeatureExtractor(QWidget *parent = 0);
    ~FeatureExtractor();
    
private:
    Ui::FeatureExtractor *ui;
};

#endif // FEATUREEXTRACTOR_H
