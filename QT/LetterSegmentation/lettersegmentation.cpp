#include "lettersegmentation.h"
#include "ui_lettersegmentation.h"

LetterSegmentation::LetterSegmentation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LetterSegmentation)
{
    ui->setupUi(this);
}

LetterSegmentation::~LetterSegmentation()
{
    delete ui;
}



void LetterSegmentation::on_pushButton_clicked()
{
     cv::Mat img= cv::imread("/home/lex/Cv/Images/placas/1615.jpg");


     ///////////////////////RECOLECCION MUESTRAS CONTORNOS///////////////////////////
   //  handler.GetContourMask(img,zona1,cmuestra, 200);//obtiene los contornos para la muestra
   //  std::sort(cmuestra.begin(), cmuestra.end(),compareContourAreas);//ordena los contornos por area de mayor a menor

     //cv::drawContours(img,cmuestra,32,Scalar(0,0,0),1,8);

     extractor.GetLetters(img);
     QImage img2= QImage((const uchar*)(img.data),img.cols,img.rows,img.step, QImage::Format_RGB888);
     ui->label->setPixmap(QPixmap::fromImage(img2));//muestra imagen en label 2


     cv::waitKey(0);
}




void LetterSegmentation::on_pushButton_2_clicked()
{

    if(extractor.placaCorregida.data){
    QImage img2= QImage((const uchar*)(extractor.placaCorregida.data),extractor.placaCorregida.cols,extractor.placaCorregida.rows,extractor.placaCorregida.step, QImage::Format_RGB888);
    ui->label_2->setPixmap(QPixmap::fromImage(img2));//muestra imagen en label 2
    }



}
