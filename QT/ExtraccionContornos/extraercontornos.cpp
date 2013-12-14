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

void ExtraerContornos::save_image(Mat src, int index, char *extencion)
{
    QString path=save_path;

    if(index<10 && index>0)
        path.append("000");
    else if(index<100 && index>=10)
        path.append("00");
    else if(index<1000 && index>=100)
        path.append("0");
    path.append(QString("%1").arg(index));
    path.append(extencion);

    cv::imwrite(path.toStdString().c_str(),src);


}

void ExtraerContornos::set_save_path(char *path)
{
    save_path=path;
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

    for(int i=0;i<10;i++)
        {


            CtrLetras[i]=cmuestra.size() - 11 + CtrLetras[i];
            if((CtrLetras[i]) > (cmuestra.size() -1))CtrLetras[i]=0;

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

    unsigned long long i=0;
    /////////////////////////LECTURA BASE DE DATOS/////////////////////////////
    //std::string path;
       QString path;
       int index2=0;
        //cv::Mat immuestra = cv::imread("C:/Users/Usuario/Documents/UdeA/2013-2/inteligencia/placas/placas/0459.jpg",0);
       set_save_path("/home/lex/Cv/Images/Letras2/");
       for(int index=1;index<1500;index++)
       {


           path="/home/lex/Cv/Images/Sabado_23/";
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
            cv::Mat PlacaMostrar2;
            cv::Mat binarizada;
             cv::Mat letra;
            cv::cvtColor(source,PlacaMostrar,CV_BGR2GRAY);
            cv::cvtColor(source,PlacaMostrar2,CV_BGR2GRAY);
            vector<int>   CtrLetras(10);

            ///////////////////////RECOLECCION MUESTRAS CONTORNOS///////////////////////////
            equalizeHist(PlacaMostrar,PlacaMostrar);
            cv::threshold(PlacaMostrar, PlacaMostrar, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);//binarizado variable
            handler.GetContourMask(PlacaMostrar,binarizada,cmuestra, 200);//obtiene los contornos para la muestra
            std::sort(cmuestra.begin(), cmuestra.end(),compareContourAreas);//ordena los contornos por area de mayor a menor

            if(cmuestra.size() <10){
                index2++;
                qDebug()<<"iteracion:"<<index2;
                continue;

            }

            //Correlacion entre areas de contornos
            CtrLetras=findCharacters(cmuestra);
            //cv::waitKey();
            unsigned long long limit=i+10;
            //Guarda cada contorno como imagen
            for(;i<limit;i++)
            {

                 if(abs(CtrLetras[i - limit + 10]) > (cmuestra.size() -1))CtrLetras[i - limit + 10]=0;
                //()<<"tamaño vector"<<cmuestra.size();
                //qDebug()<<"contorno #:"<<CtrLetras[i - limit + 10];

                letra=Extract(PlacaMostrar2,cmuestra,CtrLetras[i - limit + 10]);

                imshow("letra",letra);
                save_image(letra,i,".jpg");

            }

       }
}
