#include "segmentation.h"

Segmentation::Segmentation()
{
}


/**************************************************************************************************
Funciones
Autor: Alexander Gómez villa - German Diez Valencia - Sebastian Guzman Obando
Descripcion:Ordena los contornos de menor a mayor
***************************************************************************************************/
// FUNCION DE COMPARACION
bool compareContourAreas ( std::vector<cv::Point> contour1, std::vector<cv::Point> contour2 ) {
    double i = fabs( contourArea(contour1) );
    double j = fabs( contourArea(contour2) );
    return ( i < j );
}

/**************************************************************************************************
Funciones
Autor: Alexander Gómez villa - German Diez Valencia - Sebastian Guzman Obando
Descripcion:Encuentra correlacion entre areas
***************************************************************************************************/

vector<int> findCharacters( vector<vector<Point> > cmuestra){

    //variables
    vector<int>   CtrLetras(7);
    double contourAreas[11];
    double contourAbs[10];
    int contCtr=0;
    int I_contContours=cmuestra.size() - 1;
    int cont=10;
    int posibleLetra=0;
    Rect placa;

    //extraen areas de contornos
    while(I_contContours> (cmuestra.size() - 12))
    {

      contourAreas[cont]=contourArea(cmuestra[I_contContours]);
      cont--;
      I_contContours--;

    }

    //Busqueda de contornos correlacionados

    for(int j=10;j>=0;j--)
    {
        for(int i=10;i>=0;i--){
        contourAbs[i]= abs(contourAreas[j]-contourAreas[i]);
        qDebug()<<"contorno numero"<<cmuestra.size() - 11 + j;
        qDebug()<<"area mayor"<<contourAreas[j];
        qDebug()<<"area menor"<<contourAreas[i];
        qDebug()<< contourAbs[i];
        if((contourAbs[i] < 300) && (contourArea(cmuestra[cmuestra.size() - 11 + j])<1000))posibleLetra++;
        }


        placa=boundingRect(cmuestra[cmuestra.size() - 11 + j]);//rectangulo contenedor de contorno

        if(posibleLetra >5 && (placa.width < placa.height)){
        CtrLetras[contCtr]=j;


        contCtr++;

        }
        posibleLetra=0;
    }


    return CtrLetras;
}


/**************************************************************************************************
Funciones
Autor: Alexander Gómez villa - German Diez Valencia - Sebastian Guzman Obando
Descripcion:Dibuja los contornos
***************************************************************************************************/

cv::Mat drawletters(cv::Mat source,vector<vector<Point> > cmuestra,vector<int>   CtrLetras)
{
    cv::Mat src;
    source.copyTo(src);
    for(int i=0;i< 7;i++)
    {
        cv::drawContours(src,cmuestra,CtrLetras[i],Scalar(255,255,0),3,8);
    }
    return src;
}


/**************************************************************************************************
Funciones
Autor: Alexander Gómez villa - German Diez Valencia - Sebastian Guzman Obando
Descripcion:devuelve la imagen sin rotacion
***************************************************************************************************/

cv::Mat correctAngle(cv::Mat source, vector<vector<Point> > cmuestra, vector<int>   CtrLetras){


    float angles[7];
    int contProm=0;

    for(int i=0;i< 7;i++)
    {

    /* qDebug()<<"contorno #:"<< CtrLetras[i];
     RotatedRect casillas;
     casillas=minAreaRect(cmuestra[CtrLetras[i]]);
     angles[i]=casillas.angle;
     if( abs(casillas.angle)>0)contProm++;*/

    }

    //angle=(angle)/contProm;


    /*RotatedRect casillas;
    casillas=minAreaRect(cmuestra[CtrLetras[3]]);
    angle=casillas.angle;

    qDebug()<<angle;*/
    //////////////ROTACION DE PLACA////////////////
/*

    Point2f src_center(source.cols/2.0F, source.rows/2.0F);
    Mat rot_mat = getRotationMatrix2D(src_center,angle  + 90, 1.0);
    Mat dst;
    warpAffine(source, dst, rot_mat, source.size());*/

    Mat dst;
   return  dst;
}


/**************************************************************************************************
Funciones
Autor: Alexander Gómez villa - German Diez Valencia - Sebastian Guzman Obando
Descripcion:Segmeta las letras de la placa
***************************************************************************************************/

void Segmentation::GetLetters(Mat source)
{
    cv::Mat PlacaMostrar;
    cv::Mat binarizada;
    cv::cvtColor(source,PlacaMostrar,CV_BGR2GRAY);
    vector<int>   CtrLetras;

    ///////////////////////RECOLECCION MUESTRAS CONTORNOS///////////////////////////
    //equalizeHist(PlacaMostrar,PlacaMostrar);
    cv::threshold(PlacaMostrar, PlacaMostrar, 200, 255, 0);//binarizado variable
    imshow("Binarizacion otsu",PlacaMostrar);
    handler.GetContourMask(PlacaMostrar,binarizada,cmuestra, 200);//obtiene los contornos para la muestra
    std::sort(cmuestra.begin(), cmuestra.end(),compareContourAreas);//ordena los contornos por area de mayor a menor


    //Correlacion entre areas de contornos
    CtrLetras=findCharacters(cmuestra);

    for(int i=0;i<=7;i++)
    {
        CtrLetras[i]=cmuestra.size() - 11 + CtrLetras[i];

    }


    float angle;

    for(int i=0;i< 7;i++)
    {

     qDebug()<<"contorno #:"<< CtrLetras[i];
     RotatedRect casillas;
     casillas=minAreaRect(cmuestra[CtrLetras[i]]);
     qDebug()<<"Angulo"<<casillas.angle;

    }




    placaCorregida=drawletters(source,cmuestra,CtrLetras);

    //placaCorregida=correctAngle(placaCorregida,cmuestra,CtrLetras);



}




/*Point2f vertices[4];
casillas.points(vertices);
for (int i = 0; i < 4; i++)
    line(source, vertices[i], vertices[(i+1)%4], Scalar(255,255,0),3);
 //cv::drawContours(source,cmuestra,CtrLetras[0],Scalar(0,0,0),3,8);*/
