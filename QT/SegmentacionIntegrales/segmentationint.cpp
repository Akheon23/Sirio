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
    cv::Mat resultafo= cv::imread("/home/lex/Cv/Images/placas/0085.jpg", 0);

    cv::Mat img;
    resultafo.copyTo(img);

    equalizeHist(img,img);
    threshold(img,img,200,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
    threshold(img,img,220,255,1);

    vector<double> integrals;
    vector<double> integrals2;
    int  picos=0;
    int  picosX=0;

    int horizontalLettersY1=30;
    int horizontalLettersY2=0;



    bool flag=false;
    bool flag2=false;


    //calculo integrales
    integrals2=integral.integralX(img);//integrales proyeccion Y
    integrals=integral.integralY(img);//integrales proyeccion X


    //Busqueda de picos

    for(int i=0;i< integrals.size()-1;i++)
    {





/*       //if(integrals[i]>500)picos++;
        if(integrals2[i]>5000  && flag==false){

            picosX++;
           // line(img,Point2f (i,0), Point2f (i,img.rows-1), Scalar(255,255,0),1);
            flag=true;

        }

        if(integrals2[i]<5000  && flag==true){

            flag=false;

        }
*/


        if(integrals[i]>9500  && flag2==false){

            picos++;
            line(img,Point2f (0,i), Point2f (img.cols-1,i), Scalar(0,0,0),1);

            flag2=true;

        }

        if(integrals[i]<10000  && flag2==true){

            flag2=false;

        }
        else{
            integrals[i]=0;

        }


        qDebug()<<"fila"<<i<<"="<<integrals[i];


        for(int i=0;i< integrals.size()-1;i++)
        {
            if(i>5 && i> horizontalLettersY2 && i<45 && integrals[i]>0)
            {
                horizontalLettersY2=i;

            }

            if( i>5 && i<horizontalLettersY1 && integrals[i]>0)
            {
                horizontalLettersY1=i;

            }

        }


    }




    cv::Mat fragmentoHorizontal=img(Rect(0,horizontalLettersY1,img.cols,horizontalLettersY2 - horizontalLettersY1));


      integrals2=integral.integralX(fragmentoHorizontal);//integrales proyeccion Y


      for(int i=0;i< integrals.size()-1;i++)
      {





        //if(integrals[i]>500)picos++;
          if(integrals2[i]>5000  && flag==false){

              picosX++;
              line(fragmentoHorizontal,Point2f (i,0), Point2f (i,img.rows-1), Scalar(255,255,0),1);
              flag=true;

          }

          if(integrals2[i]<5000  && flag==true){

              flag=false;

          }







      }


    //qDebug()<<"PicosY"<<picos;
    qDebug()<<"Picos"<<picos;
    qDebug()<<"1"<<horizontalLettersY1;
    qDebug()<<"2"<<horizontalLettersY2;


    //cv::imshow("original",resultafo);
    cv::imshow("resultado",fragmentoHorizontal);

    cv::waitKey(0);

}
