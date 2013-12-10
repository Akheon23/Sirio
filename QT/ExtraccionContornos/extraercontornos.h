#ifndef EXTRAERCONTORNOS_H
#define EXTRAERCONTORNOS_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include "Scountour/scontour.h"
#include <qdebug.h>

namespace Ui {
class ExtraerContornos;
}

class ExtraerContornos : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ExtraerContornos(QWidget *parent = 0);
    ~ExtraerContornos();

    Scontour handler;
    vector<vector<Point> > cmuestra;//contornos muestra
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::ExtraerContornos *ui;
};

#endif // EXTRAERCONTORNOS_H
