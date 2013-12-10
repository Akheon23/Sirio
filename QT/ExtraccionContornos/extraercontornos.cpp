#include "extraercontornos.h"
#include "ui_extraercontornos.h"





/**************************************************************************************************
Destructor y constructor
***************************************************************************************************/
ExtraerContornos::ExtraerContornos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExtraerContornos)
{
    ui->setupUi(this);
}



ExtraerContornos::~ExtraerContornos()
{
    delete ui;
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
    vector<int>   CtrLetras(10);
    double contourAreas[11];
    int contCtr=0;
    int I_contContours=cmuestra.size() - 1;
    int cont=10;
    Rect placa;

    //extraen areas de contornos
    while(I_contContours> (cmuestra.size() - 12))
    {

      contourAreas[cont]=contourArea(cmuestra[I_contContours]);
      cont--;
      I_contContours--;

    }

    //Busqueda de contornos que cumplan criterio de dimensiones

    for(int j=10;j>=0;j--)
    {


        placa=boundingRect(cmuestra[cmuestra.size() - 11 + j]);//rectangulo contenedor de contorno

        if((placa.width < placa.height)){
        CtrLetras[contCtr]=j;
        contCtr++;

        }

    }
    return CtrLetras;

}


/**************************************************************************************************
Funciones
Autor: Alexander Gómez villa - German Diez Valencia - Sebastian Guzman Obando
Descripcion:devuelve la imagen del contorno
***************************************************************************************************/

cv::Mat Extract(cv::Mat source,vector<vector<Point> > cmuestra,int  CtrLetras)
{

    /////variables//////
    cv::Mat src;
    cv::Mat imageROI;
    cv:: Rect placa;
    source.copyTo(src);

    ///extraccion bounding rect
     placa=boundingRect(cmuestra[CtrLetras]);//rectangulo contenedor de contorno
     imageROI=src(Rect(placa.x,placa.y,placa.width,placa.height));//obtiene area de interes

    return imageROI;
}



/**************************************************************************************************
Funciones
Autor: Alexander Gómez villa - German Diez Valencia - Sebastian Guzman Obando
Descripcion:Al presionar el boton
***************************************************************************************************/
void ExtraerContornos::on_pushButton_clicked()
{


    /////////////////////////LECTURA BASE DE DATOS/////////////////////////////
    //std::string path;
       QString path;
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



            cv::Mat source=cv::imread(path.toStdString().c_str());
            /////////////////////////Variables//////////////////////////////
            cv::Mat PlacaMostrar;
            cv::Mat binarizada;
             cv::Mat letra;
            cv::cvtColor(source,PlacaMostrar,CV_BGR2GRAY);
            vector<int>   CtrLetras(10);

            ///////////////////////RECOLECCION MUESTRAS CONTORNOS///////////////////////////
            equalizeHist(PlacaMostrar,PlacaMostrar);
            cv::threshold(PlacaMostrar, PlacaMostrar, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);//binarizado variable
            handler.GetContourMask(PlacaMostrar,binarizada,cmuestra, 200);//obtiene los contornos para la muestra
            std::sort(cmuestra.begin(), cmuestra.end(),compareContourAreas);//ordena los contornos por area de mayor a menor

            //Correlacion entre areas de contornos
            CtrLetras=findCharacters(cmuestra);
            cv::waitKey();

            //Guarda cada contorno como imagen
            for(int i=0;i<10;i++)
            {
                //letra=Extract(PlacaMostrar,cmuestra,CtrLetras[i]);
            }

       }
}
