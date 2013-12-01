#ifndef FEATURETRACKER_H
#define FEATURETRACKER_H
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include "frameprocessor.h"

class FeatureTracker
{



    cv::Mat gray; //imagen gris actual
    cv::Mat gray_prev;//imagen gris anterior
    std::vector<cv::Point2f> points[2];//puntos que sera seguidos
    std::vector<cv::Point2f> initial;//posicin inicial de los puntos
    std::vector<cv::Point2f> features;// caracteristicas detectadas
    int max_count;//maxmo numero de caracteristicas a seguir
    double qlevel;//precion en la deteccion
    double minDist;//minima distancia entre 2 puntos
    std::vector<uchar> status;//estado de las caracteristicas seguidas
    std::vector<float> err;//error en el tracking
public:
    //constructor y destructor
    FeatureTracker(): max_count(500),qlevel(0.2),minDist(10){}
    ~FeatureTracker();


    //proceso para detectar puntos y seguirlos
 /*   void process(cv::Mat &frame,cv::Mat &output){

        cv::cvtColor(frame,gray,CV_BGR2GRAY);
        frame.copyTo(output);
        //revisamos si se deben añadir puntos
        if(addNewPoints()){
            detectFeaturesToTrack();
            //añadimos los puntos detectados a los puntosactualmente seguidos
            points[0].insert(points[0].end(),features.begin(),features.end());
            initial.insert(initial.end(),features.begin(),features.end());

        }

        //para la primera imagen de la secuencia
        if(gray_prev.empty())
            gray.copyTo(gray_prev);

        //para seguir los puntos
        cv::calcOpticalFlowPyrLK(
                    gray_prev,gray,//imagen actual y anterior
                    points[0],//posicion puntos en la primera imagen
                    points[1],//posicion en la siguiente
                    status,//estado de las caracteristicas seguidas
                    err);//error de tracking

        //eliminamos los puntos innecesarios
        int k=0;

        for(int i=0;i < points[1].size();i++){

            if(acceptTrackedPoint(i)){//mantenemos este punto en el vector?
                initial[k]=initial[i];//mantenganlo alli
                points[1][k++]=points[1][k];
            }

        }

        //eliminamos los puntos innecesarios
        points[1].resize(k);
        initial.resize(k);


        //para dibujar la trayectoria
        handleTrackedPoints(frame,output);

        //los actuales se vuelven los anteriores
        std::swap(points[1],points[0]);
        cv::swap(gray_prev,gray);

    }*/



    //metodo sin process
    void Track(cv::Mat &frame,cv::Mat &output){

        cv::cvtColor(frame,gray,CV_BGR2GRAY);
        frame.copyTo(output);
        //revisamos si se deben añadir puntos
        if(addNewPoints()){
            detectFeaturesToTrack();
            //añadimos los puntos detectados a los puntosactualmente seguidos
            points[0].insert(points[0].end(),features.begin(),features.end());
            initial.insert(initial.end(),features.begin(),features.end());

        }

        //para la primera imagen de la secuencia
        if(gray_prev.empty())
            gray.copyTo(gray_prev);

        //para seguir los puntos
        cv::calcOpticalFlowPyrLK(
                    gray_prev,gray,//imagen actual y anterior
                    points[0],//posicion puntos en la primera imagen
                    points[1],//posicion en la siguiente
                    status,//estado de las caracteristicas seguidas
                    err);//error de tracking

        //eliminamos los puntos innecesarios
        int k=0;

        for(int i=0;i < points[1].size();i++){

            if(acceptTrackedPoint(i)){//mantenemos este punto en el vector?
                initial[k]=initial[i];//mantenganlo alli
                points[1][k++]=points[1][k];
            }

        }

        //eliminamos los puntos innecesarios
        points[1].resize(k);
        initial.resize(k);


        //para dibujar la trayectoria
        handleTrackedPoints(frame,output);

        //los actuales se vuelven los anteriores
        std::swap(points[1],points[0]);
        cv::swap(gray_prev,gray);

    }

    //detecta puntos a seguir
    void detectFeaturesToTrack(){

    cv::goodFeaturesToTrack(gray,//imagen
                               features,//caracteristicas detectadas
                               max_count,//maximo numero de caracacteristcas
                               qlevel,//nivel de detalle
                               minDist);//distancia entre puntos

    }


    //determina si debo buscar mas puntos
    bool addNewPoints(){
        return points[0].size() <=10;//si hay menos q 10

    }

    //rechazamos algunos puntos que no deseamos seguir
    bool acceptTrackedPoint(int i){//en este caso aquellos que no se movieron
        return status[i] && (abs(points[0][i].x - points[1][i].x)+
                             (abs(points[0][i].y - points[1][i].y)) >2);



    }



    //para dibujar trayectoria
    void handleTrackedPoints(cv::Mat &frame,cv::Mat &output){
        for(int i=0; i<points[1].size(); i++){
            cv::line(output,
                     initial[i],//dessw posicion inicial
                     points[1][i],//hasta nueva posicion
                     cv::Scalar(255,255,255));
            cv::circle(output,points[1][i],3,cv::Scalar(255,255,255), -1);

        }


    }

};

#endif // FEATURETRACKER_H
