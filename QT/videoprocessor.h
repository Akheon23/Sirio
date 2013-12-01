#ifndef VIDEOPROCESSOR_H
#define VIDEOPROCESSOR_H
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

class VideoProcessor
{
public:
    //VideoProcessor();
   // ~VideoProcessor();

    ////////////////////////////VARIABLES////////////////////////////////////

    cv::VideoCapture capture;//objeto tipo video
    void (*process)(cv::Mat&,cv::Mat&);//funcion para procesar cada frame
    bool callIt;//para saber si la funcion de procesamiento fue llamada
    std::string windowNameInput;//nombre de la ventana param ostrar imagen de entrada
    std::string windowNameOutput;//nombre de la ventana param ostrar imagen de salida
    int delay;//retraso de de cada frame
    long fnumber;//numero de frames procesado
    long frameToStop;//para cuando llegue a este frame
    bool stop;//para parar el procesamiento
    VideoProcessor() : callIt(true),delay(0),fnumber(0),stop(false),frameToStop(-1){}


    //constructor
    ~VideoProcessor();


    ///////////////////////////////METODOS/////////////////////////////////////

    //asigna la funcion que va ser llamada cada frame
    void setFrameProcessor(void (*frameProcessingCallback)(cv::Mat &, cv::Mat &))
    {
        process= frameProcessingCallback;
    }


    //abre un archivo de video
    bool setInput(std::string filename)
    {
        fnumber=0;//reinicia el numero de frames procesados
        capture.release();//en caso de haber otro video abierto lo cierra
        images.clear();
        return capture.open(filename);//abre el archivo de video

    }

    //muestra frame de entrada
    void displayInput(std::string wn){
        windowNameInput=wn;
        cv::namedWindow(windowNameInput);
    }

    //muestra frame de salida
    void displayOutput(std::string wn){
        windowNameOutput=wn;
        cv::namedWindow(windowNameOutput);
    }

    //loop de video
    void run(){

        cv::Mat frame;//frame actual
        cv::Mat output;//salida

        if(!isOpened())return;//si no hay un video o camara
        stop=false;

        while(!isStopped()){

            if(!readNextFrame(frame))break;//lee si hay frame siguiente
            if(windowNameInput.length()!=0)cv::imshow(windowNameInput,frame);
            if(callIt){

                process(frame, output);
                fnumber++;

            }else{

                output=frame;

            }

            if(windowNameOutput.length()!=0)cv::imshow(windowNamedOutput,output);
            if(delay>=0 && cv::waitKey(delay)>=0)stopIt();
            if(frameToStop>=0 && getFrameNumber()==frameToStop)stopIt();


        }

    }


    //detiene el procesamiento
    void stopIt(){
    stop=true;
    }

    //verifica si el procesamiento esta detenido
    bool isStopped(){
    return stop;
    }

    //verifica si hay video
    bool isOpened(){
    capture.isOpened();
    }

    //coloca el retraso para cada frame, negativo indica que no hay
    void setDelay(int d){
    delay=d;
    }

    //obtiene el siguiente frame
    bool readNextFrame(cv::Mat& frame){
    return capture.read(frame);
    }

    //indica queremos usar funcion para procesar
    void callProcess(){
    callIt=true;
    }


    void dontCallProcess(){
    callIt=false;
    }


    //parar el proceso en un frame determinado
    void stopAtFrameNo(long frame){
    frameToStop=frame;
    }

    //retorna el numero del frame siguiente
    long getFrameNumber(){

        long fnumber=static_cast<long>(capture.get(CV_CAP_PROP_POS_FRAMES));
        return fnumber;
    }

};

#endif // VIDEOPROCESSOR_H
