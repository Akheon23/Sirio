#include "segmentationint.h"
#include "ui_segmentationint.h"

SegmentationINT::SegmentationINT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SegmentationINT)
{
    ui->setupUi(this);
}

SegmentationINT::~SegmentationINT()
{
    delete ui;
}

void SegmentationINT::on_pushButton_clicked()
{

    //carga de recursos
    cv::Mat img= cv::imread("/home/lex/Cv/Images/placas/1360.jpg", 0);
    threshold(img,img,200,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
    threshold(img,img,200,255,1);
    cv:Mat resultafo;
    vector<double> integrals;
    vector<double> integrals2;
    int  picos=0;
    int  picosX=0;
    bool flag=false;
    bool flag2=false;


    //calculo integrales
    integrals2=integral.integralX(img);
    integrals=integral.integralY(img);


    //Busqueda de picos

    for(int i=0;i< integrals.size()-1;i++)
    {

        //if(integrals[i]>500)picos++;
        if(integrals2[i]>5000  && flag==false){

            picosX++;
           // line(img,Point2f (i,0), Point2f (i,img.rows-1), Scalar(255,255,0),1);
            flag=true;

        }

        if(integrals2[i]<5000  && flag==true){

            flag=false;

        }



        if(integrals[i]>5000  && flag2==false){

            picos++;
            line(img,Point2f (0,i), Point2f (img.cols-1,i), Scalar(255,255,255),1);
            flag2=true;

        }

        if(integrals[i]<5000  && flag2==true){

            flag2=false;

        }
        qDebug()<<integrals2[i];

    }

    //qDebug()<<"PicosY"<<picos;
    qDebug()<<"Picos"<<picos;
    cv::imshow("original",img);
    cv::waitKey(0);

}
