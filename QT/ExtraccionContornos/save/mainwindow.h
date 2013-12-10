#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <stdio.h>
#include <stdlib.h>

#include <QDebug>
#include <opencv2/opencv.hpp>

#include<iostream>
#include <fstream>
#include <string>
#include <cstdlib>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_save_path(char *path);
    void set_read_path(char* path);
    void on_pushButton_clicked();
    void save_image(cv::Mat src, int index,char *extencion);
    cv::Mat open_image(int index, char *extencion);
    const char *save_path;
    const char *read_path;
    
private slots:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
