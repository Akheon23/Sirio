#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void canny(cv::Mat& img,cv::Mat& out){
    if(img.channels()==3)
        cv::cvtColor(img,out,CV_BGR2GRAY);
    cv::Canny(out,out,100,200);
    cv::threshold(out,out,128,255,cv::THRESH_BINARY_INV);

}

void MainWindow::on_pushButton_clicked()
{

   VideoProcessor processor;
   FeatureTracker tracker;
   processor.setInput("/home/lex/Videos/Sword Art Online - Without You AMV.mp4");
   //processor.setFrameProcessor(&tracker);
   processor.displayInput("current frame");
   processor.displayOutput("output frame");
   processor.setDelay(33);
   //processor.setFrameProcessor(canny);
   processor.run();

}
