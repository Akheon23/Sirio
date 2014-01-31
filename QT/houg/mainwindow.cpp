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


/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Extrae firma de la imagen
***************************************************************************************************/

void get_firma_binary_changes(cv::Mat src, int num_lines, int *src_firma)
{
    num_lines=num_lines+1;// se le suma 1 para conciderar las lineas horizontales y verticales
    double divisiones= 3.14159265358979323846 /(num_lines*2);// para hallar la separacion en radianes entre lineas
    int y;// variable auxiliar usada para describir los rayos a partir de los cuales se analiza la imagen
    int y_;// variable auxiliar usada para describir los rayos a partir de los cuales se analiza la imagen
    int x;// variable auxiliar usada para describir los rayos a partir de los cuales se analiza la imagen
    int x_;// variable auxiliar usada para describir los rayos a partir de los cuales se analiza la imagen
    int pixel_ant;// variable auxiliar usada para analizar los cambios en el valor de los pixeles a lo largo de los radios
    int pixel_init;// variable auxiliar usada para analizar los cambios en el valor de los pixeles a lo largo de los radios
    int cont_cambios=0;// contador de cambios de valor en los pixeles a lo largo de los radios
    double m=0;//variable auxiliar que guarda la pendiente de cada radio
    int index=0;// contador auxiliar usado para archivar en src_firma los cambios en cada radio

    for(int i=0;i<=num_lines;i++)// ciclo principal donde se trazan los radios
    {
        m=(double)i*divisiones;// ajuste de la pendiente para cada iteracion

        if(m>3.14159265358979323846/2.1)// para evitar problemas con la discontinuidad de la tangente en pi/2
        {
            for(int y=0; y<src.rows/2-1 ;y++)// trazado del radio inferior vertical
            {
                if(y==0)// se toma el valor del pixel de inicio, como la imagen es binaria puede ser 0 o 255
                {
                    pixel_ant=src.at<uchar>(y+src.rows/2,src.cols/2);
                    pixel_init=pixel_ant;
                }
                else
                {
                    if(pixel_ant != src.at<uchar>(y+src.rows/2,src.cols/2))
                    {
                        pixel_ant=src.at<uchar>(y+src.rows/2,src.cols/2);
                        if(pixel_ant==pixel_init)
                            cont_cambios++;

                    }
                }
            }


            *(src_firma+index)=cont_cambios;

            index++;
            cont_cambios=0;

            for(int y=src.rows/2; y>1 ;y--)// trazado del radio inferior vertical
            {

                if(y==0)// se toma el valor del pixel de inicio, como la imagen es binaria puede ser 0 o 255
                {
                    pixel_ant=src.at<uchar>(y,src.cols/2);
                    pixel_init=pixel_ant;
                }
                else
                {
                    if(pixel_ant != src.at<uchar>(y,src.cols/2))
                    {
                        pixel_ant=src.at<uchar>(y,src.cols/2);
                        if(pixel_ant==pixel_init)
                            cont_cambios++;

                    }
                }
            }


            *(src_firma+index)=cont_cambios;
            cont_cambios=0;
            index++;
            continue;
        }
        else if(m==0.00)
        {
            for(int x=0; x<src.cols/2-1 ;x++)// trazado del radio derecho
            {
                if(x==0)// se toma el valor del pixel de inicio, como la imagen es binaria puede ser 0 o 255
                {
                    pixel_ant=src.at<uchar>(src.rows/2,x);
                    pixel_init=pixel_ant;
                }
                else
                {
                    if(pixel_ant != src.at<uchar>(src.rows/2,x))
                    {
                        pixel_ant=src.at<uchar>(src.rows/2,x);
                        if(pixel_ant==pixel_init)
                            cont_cambios++;

                    }
                }
            }


            *(src_firma+index)=cont_cambios;
            index++;
            cont_cambios=0;

            for(int x=src.cols/2; x<src.cols-1 ;x++)// trazado del radio izquierdo
            {
                if(x==0)// se toma el valor del pixel de inicio, como la imagen es binaria puede ser 0 o 255
                {
                    pixel_ant=src.at<uchar>(src.rows/2,x);
                    pixel_init=pixel_ant;
                }
                else
                {
                    if(pixel_ant != src.at<uchar>(src.rows/2,x))
                    {
                        pixel_ant=src.at<uchar>(src.rows/2,x);
                        if(pixel_ant==pixel_init)
                            cont_cambios++;

                    }
                }
            }


            *(src_firma+index)=cont_cambios;
            cont_cambios=0;
            index++;

            continue;
        }
        else
        {
            m=tan(m);
            for(int x=0; x<src.cols/2-1 ;x++) // trazado de los radios del primer cuadrante
            {
                y=m*(x);
                if(abs(y)>src.rows/2-1)
                    break;
                if(x==0)// se toma el valor del pixel de inicio, como la imagen es binaria puede ser 0 o 255
                {
                    pixel_ant=src.at<uchar>(y+src.rows/2,x+src.cols/2);
                    pixel_init=pixel_ant;
                }
                else
                {
                    if(pixel_ant != src.at<uchar>(y+src.rows/2,x+src.cols/2))
                    {
                        pixel_ant=src.at<uchar>(y+src.rows/2,x+src.cols/2);
                        if(pixel_ant==pixel_init)
                            cont_cambios++;

                    }
                }
            }


            *(src_firma+index)=cont_cambios;
            index++;
            cont_cambios=0;

            for(int x=0; x<src.cols/2-1 ;x++)// trazado de los radios del segundo cuadrante
            {
                y=(x)*(m);
                x_=src.cols/2-x;
                if(abs(y)>=src.rows/2-1)
                    break;


                if(x==0)// se toma el valor del pixel de inicio, como la imagen es binaria puede ser 0 o 255
                {
                    pixel_ant=src.at<uchar>(y+src.rows/2,x_);
                    pixel_init=pixel_ant;
                }
                else
                {
                    if(pixel_ant != src.at<uchar>(y+src.rows/2,x_))
                    {
                        pixel_ant=src.at<uchar>(y+src.rows/2,x_);
                        if(pixel_ant==pixel_init)
                            cont_cambios++;

                    }
                }
            }

            *(src_firma+index)=cont_cambios;
            index++;
            cont_cambios=0;

            for(int x=0; x<src.cols/2-1 ;x++)// trazado de los radios del tercer cuadrante
            {
                y=(x)*(m);
                x_=src.cols/2-x;
                Hog H_featHog;
                vector<float> b;
                int Xresize=15;//tamaño en x de la imagen con cambio de tamaño
                int Yresize=30; //tamaño en y de la imagen con cambio de tamaño

                y_=src.rows/2-y;
                if(abs(y)>=src.rows/2-1)
                    break;

                if(x==0)// se toma el valor del pixel de inicio, como la imagen es binaria puede ser 0 o 255
                {
                    pixel_ant=src.at<uchar>(y_,x_);
                    pixel_init=pixel_ant;
                }
                else
                {
                    if(pixel_ant != src.at<uchar>(y_,x_))
                    {
                        pixel_ant=src.at<uchar>(y_,x_);
                        if(pixel_ant==pixel_init)
                            cont_cambios++;

                    }
                }
            }


            *(src_firma+index)=cont_cambios;
            index++;
            cont_cambios=0;


            for(int x=0; x<src.cols/2-1 ;x++)// trazado de los radios del cuarto cuadrante
            {
                y=m*(x);
                y_=src.rows/2-y;
                if(abs(y)>=src.rows/2-1)
                    break;

                if(x==0)// se toma el valor del pixel de inicio, como la imagen es binaria puede ser 0 o 255
                {
                    pixel_ant=src.at<uchar>(y_,x+src.cols/2);
                    pixel_init=pixel_ant;
                }
                else
                {
                    if(pixel_ant != src.at<uchar>(y_,x+src.cols/2))
                    {
                        pixel_ant=src.at<uchar>(y_,x+src.cols/2);
                        if(pixel_ant==pixel_init)
                            cont_cambios++;

                    }
                }
            }


            *(src_firma+index)=cont_cambios;
            index++;
            cont_cambios=0;
        }
    }
}

/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: rota imagen
***************************************************************************************************/
//correccion de la posicion

cv::Mat rotacion(cv::Mat src,double angle){

cv::Point2f src2(src.cols/2.0F, src.rows/2.0F);
cv::Mat rot_mat;


    rot_mat = getRotationMatrix2D(src2,angle, 1.0);

cv::Mat dstrot;
cv::warpAffine(src, dstrot, rot_mat, src.size(), cv::INTER_CUBIC,
               cv::BORDER_CONSTANT,
               cv::Scalar(255,255,255));//ROTACION

return dstrot;

}



/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Alinea las letras verticalmente
***************************************************************************************************/
cv::Mat fourierAlienation(cv::Mat img,double &correc)
{

    Fourier f;



    cv::Mat imgF;//imagen en frecuencia
    int tamanoVect=0;//numero de componentes frecuencia

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


    //Dibujo linea
    double* x = &posicionesX[0];
    double* y = &posicionesY[0];
     LinearRegression lr(x, y,tamanoVect);  // create with two arrays


      qDebug()<<(imgF.cols-1)*lr.b + lr.a;
      qDebug()<<(1)*lr.b + lr.a;
      line(imgF,Point2f (1,(1)*lr.b + lr.a ), Point2f (imgF.cols-1,(imgF.cols-1)*lr.b + lr.a ), Scalar(255,255,255),1);

    //calculo angulo de correcion

      int angle=(atan(lr.b))*180/2*3.14;

      //correccion de la posicion



      cv::Point2f src_center(imgF.cols/2.0F, img.rows/2.0F);
      cv::Mat rot_mat;


          rot_mat = getRotationMatrix2D(src_center,angle/2, 1.0);
          correc=angle/2;

      cv::Mat dstrot;
      cv::warpAffine(img, dstrot, rot_mat, img.size(), cv::INTER_CUBIC,
                     cv::BORDER_CONSTANT,
                     cv::Scalar(255,255,255));//ROTACION

      return dstrot;


}



/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Discretiza la imagen
***************************************************************************************************/


void colorReduceEfficient(cv::Mat &image, int div)//para imagenes que no estan rellenas del todo
{
    int nl=image.rows;
    int nc=image.cols;

    if(image.isContinuous())
    {
        //then no padded pixels
        nc=nc*nl;
        nl=1;//it is now a 1D array
    }
    //this loop is executed only once in case of a continuous image
    for(int j=0; j<nl; j++)
    {
        uchar* data= image.ptr<uchar>(j);
        for(int i=0; i<nc; i++)
        {
            //process each pixel
            data[i]=data[i]/div*div +div/2;
            //end pixel processing
        }//end for
    }//end for

}

/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Discretiza la imagen
***************************************************************************************************/
bool compareContourLength ( cv::Vec4i line1, cv::Vec4i line2 )//ordena de mayor longitud a menor con distancia euclidiana
{
  double i = fabs( pow(((line1[0]-line1[2])*(line1[0]-line1[2]))+((line1[1]-line1[3])*(line1[1]-line1[3])),0.5) );
  double j = fabs( pow(((line2[0]-line2[2])*(line2[0]-line2[2]))+(line2[1]-line2[3])*(line2[1]-line2[3]),0.5) );
  //qDebug()<< "distancia del primero"<< i<< "distancia del segundo"<< j<< "en la q voy";
  return ( i > j );
}

/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: main
***************************************************************************************************/
void MainWindow::on_pushButton_clicked()
{

    cv::Mat _M_SE3x5=cv::getStructuringElement(cv::MORPH_RECT,cv::Size(3,3));
    cv::Mat dst, color_dst,src;
    cv::Mat rot_mat;
    //std::string path;
    QString path;
    double angle=0;
    //cv::Mat immuestra = cv::imread("C:/Users/Usuario/Documents/UdeA/2013-2/inteligencia/placas/placas/0459.jpg",0);
    for(int index=9;index<1500;index++)
    {
        path="/home/lex/Cv/Images/placas/";
        if(index<10 && index>0)
            path.append("000");
        else if(index<100 && index>=10)
            path.append("00");
        else if(index<1000 && index>=100)
            path.append("0");
        path.append(QString("%1").arg(index));
        path.append(".jpg");
        //path<<(string)index;


        cv::Mat src_peq=cv::imread(path.toStdString().c_str(),0);

        cv::resize(src_peq,src,cv::Size(round(3*src_peq.cols),round(3*src_peq.cols)),3,3);
        cv::threshold(src,dst,150,255,CV_THRESH_BINARY);
        Canny( dst, dst, 50, 200, 3 );
        cv::morphologyEx(dst,dst, CV_MOP_GRADIENT ,_M_SE3x5);
        cvtColor( dst, color_dst, CV_GRAY2BGR );


        std::vector<cv::Vec4i> lines;
        HoughLinesP( dst, lines, 1, CV_PI/180, 80, 30, 10 );
        std::sort(lines.begin(), lines.end(),compareContourLength);//ordena los contornos por area de mayor a menor
        for( int i = 0; i < 1; i++ )
        {
            line( color_dst, cv::Point(lines[i][0], lines[i][1]),cv::Point(lines[i][2], lines[i][3]), cv::Scalar(0+40*i,0+30*i,255), 3, 8 );
            cv::namedWindow( "Detected Lines", 1 );
            cv::imshow( "Detected Lines", color_dst );
        }
        angle=180*atan2((lines[1][1]-lines[1][3]),(lines[1][0]-lines[1][2]))/CV_PI;
        qDebug()<<angle;

        cv::Point2f src_center(color_dst.cols/2.0F, color_dst.rows/2.0F);
        if(abs(angle)>120)
        {

            rot_mat = getRotationMatrix2D(src_center,angle-180  , 1.0);
        }
        else if(abs(angle)<120&&abs(angle)>50)
        {
            rot_mat = getRotationMatrix2D(src_center,angle-80  , 1.0);
            qDebug()<<"patata";
        }
        cv::Mat dstrot;
        cv::warpAffine(src, dstrot, rot_mat, color_dst.size());//ROTACION horizontal
        imshow("rotada no cortada",dstrot);

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////SEGMENTACION HORIZONTAL/////////////////////////////////////////////////


        cv::Mat img;
        cv::Mat img2;
        cv::Mat img3;
        dstrot.copyTo(img2);
        //cvtColor(img2,img3,CV_GRAY2BGR);
        cv::Mat fragmentoHorizontal;
        colorReduceEfficient(img2,64);
       // imshow("discretizada",img2);
        equalizeHist(img2,img2);
        threshold(img2,img,200,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
        threshold(img,img,220,255,1);

       vector<double> integralsline;
        vector<double> integrals;//integralesen direccion Y
        vector<double> integrals2;//integralesen direccion X
        int cambios[3];
        int  picos=0;
        int  picosX=0;


        //calculo integrales
        integrals=integral.integralY(img);//integrales proyeccion X
        integralsline=integral.integralYline(img);//integrales proyeccion X

        int prom=0;

        //Calculo promedio

        for(int i=0;i< integrals.size()-1;i++)//calcula el promedio de cambios verticales por placa
         {
            prom+=integralsline[i];
        }

        prom=prom/integrals.size();

        //Segmentacion de zona

       for(int i=0;i< integrals.size()-1;i++)
        {





           if(integralsline[i]>prom)
           {



               line(img,Point2f (0,i), Point2f (img.cols-1,i), Scalar(255,255,255),3);
               integralsline[i]=1;

           }else{

               integralsline[i]=0;

           }


        }


       cv::Mat imageROI;
       bool area=false;
       bool zona=false;
       bool guarde=false;
       int tamano=0;
       int masgrande=0;
       int inicio=0;
       int inicioTemp=0;
       int final=0;

       for(int i=2;i< integrals.size()-1;i++)
        {

            if(integralsline[i]>0 && integralsline[i-1]>0)
            {
                tamano++;
                if(zona==false)area=true;
                zona=true;
             }

                if(zona==true && integralsline[i]<1)
                {
                    if(tamano>masgrande)
                    {
                        masgrande=tamano;
                        tamano=0;
                        final=i;
                        inicio=inicioTemp;
                    }

                 }


            if(integralsline[i]<1)
            {

                zona=false;
            }

            if(area==true && integralsline[i-2]<1){
                inicioTemp=i;
                area==false;

            }

        }

       qDebug()<<"inicio:"<<inicio;
       qDebug()<<"final:"<<final;

       imageROI=dstrot(Rect(0,inicio-10,img.cols,final-inicio + 10));//obtiene area de interes HORIZONTAL

        // cv::imshow("resultado",fragmentoHorizontal);


cv::Mat imageROI2;
       bool flag=false;
     threshold(imageROI,imageROI2,200,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
      threshold(imageROI2,imageROI2,200,255,0);
      imshow("tratada1",imageROI);
     imshow("tratada2",imageROI2);



        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       ///////Alinecion vertical

     double correc=0;
       cv::Mat Corregida=fourierAlienation(imageROI,correc);
       imshow("corregida2",Corregida);

       ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

       //Busqueda de picos

       bool flag2=false;
       picos=0;

       //calculo integrales

       vector<double> integral3;
       int contZonas=0;
       threshold(Corregida,Corregida,200,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
       threshold(Corregida,Corregida,250,255,1);
       integral3=integral.integralX(Corregida);//integrales proyeccion Y

       //segmentacion de zonas

       bool borde=false;
       for(int i=0;i< integral3.size()-1;i++)
       {



           if(integral3[i]<10 && borde==false)
           {
               line(Corregida,Point2f (i,0), Point2f (i,Corregida.rows), Scalar(255,255,255),1);
               contZonas++;
               borde=true;
           }
          if(integral3[i]>10 && borde==true)
           {

               borde=false;
           }


       }

       vector<int> segmentacionx(contZonas+2);


       borde=false;
       contZonas=0;
              for(int i=0;i< integrals.size()-1;i++)
              {



                  if(integral3[i]<10 && borde==false)
                  {
                      line(Corregida,Point2f (i,0), Point2f (i,Corregida.rows), Scalar(255,255,255),1);
                      contZonas++;
                      segmentacionx[contZonas]=i;
                      borde=true;

                  }
                 if(integral3[i]>10 && borde==true)
                  {

                      borde=false;
                  }


              }


                segmentacionx[segmentacionx.size()-1]=Corregida.cols;
              for(int i=0;i<segmentacionx.size()-1;i++)
                  qDebug()<<segmentacionx[i];


//       ////////////////////////////////////////////////////////////////
//        //segmentacion de zonas

              vector<cv::Mat> letras(segmentacionx.size()+1);
              vector<cv::Mat> letras2(segmentacionx.size()+1);
              cv::Mat ultima;
              dstrot.copyTo(ultima);
              ultima=rotacion(ultima,correc);



              for(int i=0;i<segmentacionx.size()-2;i++)
              {
                  //letras[i]=Corregida(Rect(segmentacionx[i],0,segmentacionx[i+1],Corregida.rows));//obtiene area de interes
                  letras[i]=Corregida(Rect(segmentacionx[i],0,segmentacionx[i+1]-segmentacionx[i],Corregida.rows));
                  letras2[i]=ultima(Rect(segmentacionx[i],inicio-10,segmentacionx[i+1]-segmentacionx[i],Corregida.rows+10));

                  qDebug()<<"tamaño original"<<dstrot.cols;
                  qDebug()<<"tamaño corregida"<<Corregida.cols;
                  qDebug()<<"primer corte"<<int(abs(sin(angle-180)*Corregida.cols));

              }

//         //letras segmentadas

              vector<cv::Mat> letras2sobel(segmentacionx.size()+1);
             for(int i=0;i< letras.size()-3;i++)
             {

                 if(letras[i].data){
//                     cv::Sobel(letras2[i],letras2sobel[i],CV_8U,2,0);
//                       threshold(letras2sobel[i],letras2sobel[i],50,255,1);
//                     cv::add(letras2[i],letras2sobel[i],letras2[i]);

                     threshold(letras2[i],letras2[i],200,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
                    imshow("letra7", letras2[i]);


                 }
                  qDebug()<<i;
                 waitKey(0);
             }


       ////////////////////////////////////////////////Extraccion Caracteristicas///////////////////////////////////////////////////////////

//             for(i=0;i< letras.size()-3;i++)
//             {

//                 if(letras[i].data)
//                 {


//                     threshold(letras2[i],letras2[i],200,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
//                    imshow("letra7", letras2[i]);




//                     Hog H_featHog;
//                     vector<float> b;
//                     int Xresize=15;//tamaño en x de la imagen con cambio de tamaño
//                     int Yresize=30; //tamaño en y de la imagen con cambio de tamaño

//                     ////INICIA HOG//////
//                         int iter2=0;

//                      b=H_featHog.getHOG(letras2[i],Size (64,128), Size (8,8));

//                      std::vector<float>::iterator itc=H_featHog.descriptorsValues.begin();
//                                  while(itc!=H_featHog.descriptorsValues.end())
//                                  {
//                                      fout << *itc<<' ';
//                                      fout_hough << *itc<<' ';

//                                      itc=itc+1;
//                                  }


//                      ///INTEGRALES DE PROTECCION//


//                       cv::resize(letras2[i], letras2[i], Size(Xresize,Yresize) );


//                       IntegralProy integral;

//                       cv:Mat a;
//                       vector<float> b;

//                       vector<double> c;
//                       vector<double> d;

//                       c=integral.integralX(letras2[i]);
//                       d=integral.integralYletras2[i];


//                       ///INICIA FIRMA///

//                        cv::Mat dst, color_dst,src;

//                       cv::resize(letras2[i],src,cv::Size(round(6*letras2[i].cols),round(3*letras2[i].cols)),3,3);
//                       cv::threshold(src,dst,150,255,CV_THRESH_BINARY);
//                       Canny( dst, dst, 50, 200, 3 );

//                       cvtColor( dst, color_dst, CV_GRAY2BGR );
//                       cv::imshow( "binaria antes", dst);
//                       int num_lines=3;
//                       int src_firma[(num_lines+1)*4];

//                       get_firma_binary_changes(dst,3,src_firma);
//                   }

//                }
        //////////////////////////////////////////////CLASIFICACION///////////////////////////////////////////////////////////

             ///LLAMADO A LA RED

             ///////////////////////////////////////////////////////////////////////
             ///////////////// ejemplo de como usar octave embebido////////////////
             //////////////////////////////////////////////////////////////////////


             //             signalName=fileName; // Mantener el nombre del archivo en la memoria




             //                 octave_value_list filenameOct, sigInfo; // Declarar argumentos para cargar el archivo desde octave




             //                 filenameOct=octave_value(fileName); // Como argumento de entrada el nombre del archivo de la senal




             //                 sigInfo=feval("wavread",filenameOct,3); // Llamar a wavread




             //                 // Llevar a matrices los valores devueltos por wavread

             //                 signal = sigInfo(0).matrix_value();


             //                 Fs = sigInfo(1).matrix_value();;


             //                 bitRate = sigInfo(2).matrix_value();

        //////////////////////////////////////////////RESULTADOS///////////////////////////////////////////////////////////

       ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       // cv::imshow("rotada",dstrot);
        cv::imshow("img",img);
        cv::imshow("Segmentacion Horizontal",imageROI);
         cv::imshow("Correccion vertical",Corregida);

        cv::namedWindow( "Source", 1 );
        cv::imshow( "Source", src );

       // cv::namedWindow( "Detected Lines", 1 );
        //cv::imshow( "Detected Lines", color_dst );

        cv::waitKey(0);

    }

}


