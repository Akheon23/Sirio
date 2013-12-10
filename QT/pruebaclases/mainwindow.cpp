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

    SurfD feature;
      Hog H_featHog;
      cv:Mat a;
      vector<float> b;
      cv::Mat img= cv::imread("/home/lex/Pictures/2013-06-18-587586.png", 1);
      a=feature.getSurfDescriptors(img);
      b=H_featHog.getHOG(img,Size (64,128), Size (8,8));
      qDebug()<<H_featHog.descriptorsValues.size();

      ofstream fout("/home/lex/Desktop/salida1.txt");
      fout << '[';

      for(int iter=1;iter<100;iter++)
      {
          fout << *(H_featHog.descriptorsValues.data()+iter);


      }
      fout << ']';
      //fout.close();


      fout.close();

      cv::imshow("original",img);
      cv::waitKey(0);

}
