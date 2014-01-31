#include "train.h"
#include "ui_train.h"

Train::Train(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Train)
{
    ui->setupUi(this);
}

Train::~Train()
{
    delete ui;
}




QString consolesAsk(std::string command) {

    QProcess process;
    process.start(command.c_str());
    process.waitForFinished(-1);
    QByteArray out = process.readAllStandardOutput();
    QString salida=out;
    return salida;
}




//main
void Train::on_pushButton_clicked()
{
    int numero_de_placas_base=299;
    int Xresize=15;//tamaño en x de la imagen con cambio de tamaño
    int Yresize=30; //tamaño en y de la imagen con cambio de tamaño
    cv::Mat TrainData;
    TrainData.create(numero_de_placas_base,Xresize + Yresize,CV_32SC1);

    QString path;
    QString pathConsole;

//carpeta

    for(int carpeta=0;carpeta<10;carpeta++){

        path="/home/lex/Cv/Images/placasdatabase/";
        pathConsole="cd " + path;
        std::string utf8_text = pathConsole.toUtf8().constData();
        system(utf8_text.c_str());


        path.append(QString("%1").arg(carpeta));

        system(utf8_text.c_str());



        numero_de_placas_base=system(utf8_text.c_str());

        qDebug()<<consolesAsk("ls | wc -l");






        //archivo
        for(int iter=1;iter<=numero_de_placas_base;iter++)//NUMERO DE LETRAS
        {
            path.append("/");
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
                cv::resize(img, img, Size(Xresize,Yresize) );

                imshow("imagen",img);

                IntegralProy integral;

                cv:Mat a;
                vector<float> b;

                vector<double> c;
                vector<double> d;

                c=integral.integralX(img);
                d=integral.integralY(img);


                int cont=0;
                for(int i=0;i<c.size();i++)
                {

                    TrainData.at<double>(i,iter)=c[i];
                    cont++;

                }

                for(int i=cont;i<TrainData.cols;i++)
                {

                    TrainData.at<double>(i,iter)=d[i];


                }

                cv::waitKey(0);
            }

        }

    }

}
