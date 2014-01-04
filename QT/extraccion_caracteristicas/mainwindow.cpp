#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ofstream fout("/home/lex/Desktop/caract_placas/caract_Basura.dat");
    ofstream fout_hough("/home/lex/Desktop/caract_placas/caract_hougBasura.dat");
    ofstream fout_integ_proy("/home/lex/Desktop/caract_placas/integ_proyBasura.dat");


    int numero_de_placas_base=3481;

    Hog H_featHog;
    vector<float> b;
    int Xresize=15;//tamaño en x de la imagen con cambio de tamaño
    int Yresize=30; //tamaño en y de la imagen con cambio de tamaño

    Ssobel dir;
    QString path;

    for(int iter=1;iter<=numero_de_placas_base;iter++)//NUMERO DE LETRAS
    {
        path="/home/lex/Cv/Images/placasdatabase/Basura/";
        if(iter<10 && iter>0)
            path.append("000");
        else if(iter<100 && iter>=10)
            path.append("00");
        else if(iter<1000 && iter>=100)
            path.append("0");
        path.append(QString("%1").arg(iter));
        path.append(".jpg");
        //path<<(string)index;



        cv::Mat img= cv::imread(path.toStdString().c_str(), 1);// LA IMAGEN QUE VOY COGIENDO
        if(img.data)
        {



        ////////////////////////////////////////////INICIA HOG////////////////////////////////////////////
            int iter2=0;

            b=H_featHog.getHOG(img,Size (64,128), Size (8,8));






            std::vector<float>::iterator itc=H_featHog.descriptorsValues.begin();
                        while(itc!=H_featHog.descriptorsValues.end())
                        {
                            fout << *itc<<' ';
                            fout_hough << *itc<<' ';

                            itc=itc+10;
                        }



            ////////////////////////////////////////////FINALIZA HOG////////////////////////////////////////////

           ////////////////////////////////////////////INICIA INTEGRALES DE PROTECCION////////////////////////////////////////////

            // F A L T A         E L         R E S I Z E         40 X 40

                        cv::resize(img, img, Size(Xresize,Yresize) );


            IntegralProy integral;

            cv:Mat a;
            vector<float> b;

            vector<double> c;
            vector<double> d;
            c=integral.integralX(img);
            d=integral.integralY(img);

            for( iter2=0;iter2<Xresize ;iter2++)// integrales de proyeccion en x
            {
                fout << *(c.data()+iter2)<<' ';
                fout_integ_proy<< *(c.data()+iter2)<<' ';



            }

            for( iter2=0;iter2<Yresize ;iter2++)// integrales de proyeccion en y
            {
                fout << *(d.data()+iter2)<<' ';
                fout_integ_proy<< *(d.data()+iter2)<<' ';


            }

           ////////////////////////////////////////////FINALIZA INTEGRALES DE PROTECCION////////////////////////////////////////////

            ////////////////////////////////////////////INICIA SOBEL////////////////////////////////////////////


            fout << dir.getVerticalC(img,190)<<' ';
            fout <<dir.getHorizontalC(img,190)<<' ';

            fout_hough << dir.getVerticalC(img,190)<<' ';
            fout_hough <<dir.getHorizontalC(img,190)<<' ';

            fout_integ_proy << dir.getVerticalC(img,190)<<' ';
            fout_integ_proy <<dir.getHorizontalC(img,190)<<' ';



            ////////////////////////////////////////////FINALIZA SOBEL////////////////////////////////////////////

            ////////////////////////////////////////////INICIA FIRMA////////////////////////////////////////////
            ////////////////////////////////////////////FINALIZA FIRMA////////////////////////////////////////////

            fout<<'\n';
            fout_hough<<'\n';
            fout_integ_proy<<'\n';

        }

    }
    qDebug()<<"se acabo :'(";
    fout.close();
    fout_hough.close();
    fout_integ_proy.close();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{



}

