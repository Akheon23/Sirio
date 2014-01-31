#include "alineacion.h"
#include "ui_alineacion.h"

Alineacion::Alineacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alineacion)
{
    ui->setupUi(this);
}

Alineacion::~Alineacion()
{
    delete ui;
}

void Alineacion::on_pushButton_clicked()
{
    cv::Mat img;//imagen original
    cv::Mat imgF;//imagen en frecuencia
    int tamanoVect=0;//numero de componentes frecuencia



    img=imread("/home/lex/Cv/Images/Segmentacion Horizontal_screenshot_07.01.2014.png",0);

    imgF=f.getFourier(img);//obtiene transformada de fourier


    //conversion imagen flotante a entera
    double minVal, maxVal;
    minMaxLoc(imgF, &minVal, &maxVal); //find minimum and maximum intensities
    Mat draw;
    imgF.convertTo(imgF, CV_8U, 255.0/(maxVal - minVal), -minVal * 255.0/(maxVal - minVal));

    Simage::Pixval(imgF, 0,tamanoVect);//obtengo numero de componentes en frecuencia
    vector<double> posicionesX(tamanoVect);//posiciones X componentes frecuencia
    vector<double> posicionesY(tamanoVect);//posiciones Y componenetes frecuencia
    Simage::whitePix(imgF,posicionesX,posicionesY);//obtiene posiciones componentes frecuencia
    qDebug()<<tamanoVect;

    ///////////////////////////INTELIGENCIA COMPUTACIONAL////////////////////////

//    //inicializacion pesos
//    double theta0=1;//peso
//    double theta1=1;//peso
//    long  double error=1;//error en regresion
//    float tolerancia=0.6;//criterio de parada
//    double alpha=0.01;//learning rate
//    double sum=0;//sumatoria
//    double sum2=0;//sumatoria
//    double sum3=0;//sumatoria


//    //gradiente decendiente
//    while(abs(error)>tolerancia)
//    {

//        //calculo sumatorias
//        for(  int i=0;i<posicionesX.size();i++){

//             sum+= (theta0 +theta1*(posicionesX[i]) - posicionesY[i])*(posicionesX[i]);
//             sum2+= ((theta0 +theta1*(posicionesX[i]) - posicionesY[i]))*((theta0 +theta1*(posicionesX[i]) - posicionesY[i]));
//             sum3+= (theta0 +theta1*(posicionesX[i]) - posicionesY[i]);
//              //qDebug()<<sum2;
//        }



//        theta0=theta0 - alpha*((1.0/(posicionesX.size()))*sum3);//calculo gradiente
//        theta1=theta1- alpha*((1.0/posicionesX.size())*sum);//calculo gradiente

//        error=(1.0/(2*posicionesX.size()))*sum2;//calculo de funcion de costo
//        //Debug()<<"Error=" <<error;
//       // std::cout<<error<<endl;
//        sum=0;
//        sum2=0;
//        sum3=0;
//        std::cout<<theta0<<endl;
//    }

    //Dibujo linea
    double* x = &posicionesX[0];
    double* y = &posicionesY[0];
     LinearRegression lr(x, y,tamanoVect);  // create with two arrays

     cout << "Number of x,y pairs = " << lr.items() << endl;
      //cout << lr << endl;
      cout << "Coefficient of Determination = "
           << lr.getCoefDeterm() << endl;
      cout << "Coefficient of Correlation = "
           << lr.getCoefCorrel() << endl;
      cout << "Standard Error of Estimate = "
           << lr.getStdErrorEst() << endl;
      qDebug()<<lr.a;
      qDebug()<<lr.b;

      qDebug()<<(imgF.cols-1)*lr.b + lr.a;
      qDebug()<<(1)*lr.b + lr.a;
      line(imgF,Point2f (1,(1)*lr.b + lr.a ), Point2f (imgF.cols-1,(imgF.cols-1)*lr.b + lr.a ), Scalar(255,255,255),1);

    //calculo angulo de correcion

      int angle=(atan(lr.b))*180/2*3.14;

      //correccion de la posicion



      cv::Point2f src_center(imgF.cols/2.0F, img.rows/2.0F);
      cv::Mat rot_mat;


          rot_mat = getRotationMatrix2D(src_center,angle/4, 1.0);

      cv::Mat dstrot;
      cv::warpAffine(img, dstrot, rot_mat, img.size());//ROTACION



      qDebug()<<(atan(lr.b))*180/2*3.14;


    imshow("Original",img);
    imshow("frecuencia",imgF);
    imshow("corregida",dstrot);


}
