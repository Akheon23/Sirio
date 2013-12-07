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



void MainWindow::Mostrar(cv::Mat PlacaMostrar2){

    cv::Mat PlacaMostrar;
    cv::cvtColor(PlacaMostrar2,PlacaMostrar,CV_GRAY2BGR);
    QImage img2= QImage((const uchar*)(PlacaMostrar.data),PlacaMostrar.cols,PlacaMostrar.rows,PlacaMostrar.step, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img2));//muestra imagen en label 2

}

// FUNCION DE COMPARACION
bool compareContourAreas ( std::vector<cv::Point> contour1, std::vector<cv::Point> contour2 ) {
    double i = fabs( contourArea(contour1) );
    double j = fabs( contourArea(contour2) );
    return ( i < j );
}


void MainWindow::on_pushButton_clicked()
{


   cv::Mat img= cv::imread("/home/lex/Cv/Images/1cut.png", 0);
   cv::Mat PlacaMostrar;
   cv::Mat zona1;


   ///////////////////////RECOLECCION MUESTRAS CONTORNOS///////////////////////////
   handler.GetContourMask(img,zona1,cmuestra, 200);//obtiene los contornos para la muestra
   std::sort(cmuestra.begin(), cmuestra.end(),compareContourAreas);//ordena los contornos por area de mayor a menor

   cv::drawContours(img,cmuestra,32,Scalar(0,0,0),1,8);
   cv::cvtColor(img,PlacaMostrar,CV_GRAY2BGR);
   QImage img2= QImage((const uchar*)(PlacaMostrar.data),PlacaMostrar.cols,PlacaMostrar.rows,PlacaMostrar.step, QImage::Format_RGB888);
   ui->label->setPixmap(QPixmap::fromImage(img2));//muestra imagen en label 2


   cv::waitKey(0);

}
