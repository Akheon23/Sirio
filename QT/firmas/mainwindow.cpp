#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
/**************************************************************************************************
Funcion get_firma_binary_changes
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion: esta funcion recibe una imagen, el numero de lineas por cuadrante entre las lineas
horizontales y verticales que se quieren analizar y la direccion de memoria del primer elemento
de un vector de enteros donde se van a guardar los cambios de valor que hubieron en cada linea
por ende el vector del que se recibe la direccion de memoria debe tener una dimension de 4 veces
las lineas que se quiere dibujar mas uno int src_firma[(num_lines+1)*4] , incluyenro las lineas
verticales y horizontales.
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
/**************************************************************************************************
Funcion draw_firma
Autor: Sebastian Guzman Obando - Alexander Gómez villa - German Diez Valencia
Descripcion: esta funcion recibe una imagen, el numero de lineas por cuadrante entre las lineas
horizontales y verticales que se quieren analizar y devuelve una cv::Mat con los radios usados
para obtener la firma graficados.
***************************************************************************************************/
cv::Mat MainWindow::draw_firma(cv::Mat src, int num_lines)
{
    num_lines=num_lines+1;
    double divisiones= 3.14159265358979323846 /(num_lines*2);
    int y;// variable auxiliar usada para describir los rayos a partir de los cuales se analiza la imagen
    int y_;// variable auxiliar usada para describir los rayos a partir de los cuales se analiza la imagen
    int x;// variable auxiliar usada para describir los rayos a partir de los cuales se analiza la imagen
    int x_;// variable auxiliar usada para describir los rayos a partir de los cuales se analiza la imagen
    double m=0;//variable auxiliar que guarda la pendiente de cada radio

    for(int i=0;i<=num_lines;i++)
    {
        m=(double)i*divisiones;

        if(m>3.14159265358979323846/2.1)// para evitar problemas con la discontinuidad de la tangente en pi/2
        {
            for(int y=0; y<src.rows/2-1 ;y++)// trazado del radio inferior vertical
            {
                src.at<uchar>(y+src.rows/2,src.cols/2)=255;
            }
            //cv::waitKey(0);
            //cv::imshow("patata",src);
            for(int y=src.rows/2; y>1 ;y--)// trazado del radio superior vertical
            {
                src.at<uchar>(y,src.cols/2)=255;
            }
            //cv::waitKey(0);
            //cv::imshow("patata",src);
            continue;
        }

        else if(m==0.00)
        {
            for(int x=0; x<src.cols/2-1 ;x++)// trazado del radio horizontal derecho
            {
                src.at<uchar>(src.rows/2,x)=255;
            }

            //cv::waitKey(0);
            //cv::imshow("patata",src);
            for(int x=src.cols/2; x<src.cols-1 ;x++)// trazado del radio horizontal izquierdo
            {
                src.at<uchar>(src.rows/2,x)=255;
            }
            //cv::waitKey(0);
            //cv::imshow("patata",src);
            continue;
        }
        else
        {
            m=tan(m);
            //    si esta en el primer cuadrante
            for(int x=0; x<src.cols/2-1 ;x++)
            {
                y=m*(x);
                if(abs(y)>src.rows/2-1)
                    break;
                src.at<uchar>(y+src.rows/2,x+src.cols/2)=255;
            }
            //si esta en el segundo cuadrante
            for(int x=0; x<src.cols/2-1 ;x++)
            {
                y=(x)*(m);
                x_=src.cols/2-x;
                if(abs(y)>=src.rows/2-1)
                    break;
                src.at<uchar>(y+src.rows/2,x_)=255;
            }
            //si esta en el tercer cuadrante
            for(int x=0; x<src.cols/2-1 ;x++)
            {
                y=(x)*(m);
                x_=src.cols/2-x;
                y_=src.rows/2-y;
                if(abs(y)>=src.rows/2-1)
                    break;
                src.at<uchar>(y_,x_)=255;
            }
            //si esta en el cuarto cuadrante
            for(int x=0; x<src.cols/2-1 ;x++)
            {
                y=m*(x);
                y_=src.rows/2-y;
                if(abs(y)>=src.rows/2-1)
                    break;
                src.at<uchar>(y_,x+src.cols/2)=255;
            }
            //cv::waitKey(0);
            //cv::imshow("patata",src);
        }

    }

    return src;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    cv::Mat dst, color_dst,src;
    //std::string path;
    QString path;

    //cv::Mat immuestra = cv::imread("C:/Users/Usuario/Documents/UdeA/2013-2/inteligencia/placas/placas/0459.jpg",0);
    for(int index=9;index<1500;index++)
    {
        path="/home/lex/Cv/Images/placasdatabase/1/";
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

        cv::resize(src_peq,src,cv::Size(round(6*src_peq.cols),round(3*src_peq.cols)),3,3);
        cv::threshold(src,dst,150,255,CV_THRESH_BINARY);
        Canny( dst, dst, 50, 200, 3 );

        cvtColor( dst, color_dst, CV_GRAY2BGR );
        cv::imshow( "binaria antes", dst);
        int num_lines=3;
        int src_firma[(num_lines+1)*4];

        get_firma_binary_changes(dst,num_lines,src_firma);

        for(int i=0;i<(num_lines+1)*4;i++)
             qDebug()<<src_firma[i];

        dst=draw_firma(dst,num_lines);
        cv::imshow( "Source", src );
        cv::imshow( "binaria", dst);

        cv::waitKey(0);
    }
}
