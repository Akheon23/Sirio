#include "track.h"
#include "ui_track.h"

Track::Track(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Track)
{
    ui->setupUi(this);
    //TIEMPO DE ACTUALIZACION
    gTimer = new QTimer(this);
    connect(gTimer,SIGNAL(timeout()),this,SLOT(refreshFrame()));
    gTimer->start(gTimeUpdateMS=33);
    //CARGA DE RECURSOS
    camera.open("/home/lex/Cv/Videos/videos/video_13.avi");//carga video a usar
    delayForErrors=0;
    errorDetected=false;
}

Track::~Track()
{
    delete ui;
    frame.~Mat();
    image.~Mat();
}

void Track::refreshFrame()
{

    try{
        if (camera.isOpened()==true && errorDetected==false)
        {


            camera>>frame;//extrae imagen del Caputure

            cv::Mat ROI;
            ROI=frame(cv::Rect(0,115,130,115));//saca un area de interes

            //realizando el tracking
            follow.Track(frame,Output);


            //MUESTRA VIDEO EN INTERFAZ
            QImage img= QImage((const unsigned char*)(Output.data),Output.cols,Output.rows,Output.step,QImage::Format_RGB888);//extrae imagen
            ui->label->setPixmap(QPixmap::fromImage(img));//muestra en label el video

            cv::cvtColor(imageCopy,image,CV_BGR2GRAY);//obtiene frame en escala de grises



        }//FIN IF CAMERA IS OPENED
        else if(errorDetected==true)
        {
            delayForErrors++;
            if(delayForErrors>2)
            {
                delayForErrors=0;
                errorDetected=false;
            }//FIN IF "delayForErrors"
        }//FIN ELSE IF "errorDetected"
    }//FIN TRY
    catch(...)
    {
        errorDetected=true;
    }
}
