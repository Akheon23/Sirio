/***************************************************************************
* This file is part of GNoiseSuppression.
* Copyright (C) 2012 German Diez, Nicanor Garcia

* GNoiseSuppression is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* GNoiseSuppression is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with GNoiseSuppression.  If not, see <http://www.gnu.org/licenses/>.


****************************************************************************
* Authors: German Diez, Nicanor Garcia
* Contact:
* Date: 13/01/2013
****************************************************************************/

#include "plotwidget.h"
#include "ui_plotwidget.h"
#include<QString>

/*
 * Constructor por defecto
 */
plotWidget::plotWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::plotWidget)
{
    ui->setupUi(this);


    iRatio=0;// punto inicial en terminos del vector de pixeles que se toma por defecto en el que se asume que hay ruido
    fRatio=0.05;// punto final en terminos del vector de pixeles que se toma por defecto en el que se asume que hay ruido
    first=true;//bandera que indica si sobre la grafica ocurrio un primer o segundo click
    signal_in=false;// bandera que indica si ya se grafico una señal
    customPlot=ui->graphicsig;//apontador al elemento QCustomPlot
    customPlot->addGraph();// al ser necesarias tres graficas se agregan las tres con la instruccion addGraph()
    customPlot->addGraph();
    customPlot->addGraph();
    customPlot->xAxis->setTickLabels(false);
    customPlot->yAxis->setTickLabels(false);
    x = this->size().width()-customPlot->marginLeft()-customPlot->marginRight(); //tamano aproximado en pixeles de la señal
    // Conectar la senal de hacer click en la grafica con su slot
    connect(ui->graphicsig,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(mousePressEvent(QMouseEvent*)));


}
//******************************************************************************************************
/*
 * Destructor
 */

plotWidget::~plotWidget()
{
    delete ui;
}

//******************************************************************************************************

/*
 * Slot para manejar el evento que se produce al dar click en la grafica
 * Calcula la fraccion de la senal en donde se hizo click
 * Grafica un indicador en el punto
 */

void plotWidget::mousePressEvent ( QMouseEvent * event )
{
    if(signal_in && (event->x()>= customPlot->marginLeft()) && (event->x()<=customPlot->size().width()-customPlot->marginRight()))//condiciones necesarias para tomar en cuenta el evento
    {
        if (first==0){
           iRatio=(event->x()-customPlot->marginLeft())/(double)x;

           first= !first;
           graphPoint_1(iRatio*sigSize);

        }
        else{
            fRatio=(event->x()-customPlot->marginLeft())/(double)x;

            first= !first;
            graphPoint_2(fRatio*sigSize);

         }

    }
}

//******************************************************************************************************
/*
 * Grafica el primer punto seleccionado
 */

void plotWidget::graphPoint_1( double point )
{
    QVector<double> y(100), pointv(100);
    for(unsigned int i=0;i<100;i++)//crea la secuencia de puntos a graficar
    {
        y[i]=1-i/50;
        pointv[i]=point;
    }
    customPlot->graph(1)->setPen(QPen(Qt::red));//se le asigna color rojo a la grafica
    customPlot->graph(1)->setData(pointv,y);//se le asignan los vectores en cada eje que contienen la informacion de la grafica

    // crea los labels de los ejes
    //customPlot->xAxis->setLabel("Time");
    //customPlot->yAxis->setLabel("Amplitude");
    // asigna los rangos en cada eje de la grafica
    customPlot->xAxis->setRange(0, sigSize);
    customPlot->yAxis->setRange(-1, 1);
    customPlot->replot();

}
//******************************************************************************************************

/*
 * Grafica el segundo punto seleccionado
 */

void plotWidget:: graphPoint_2( double point )
{
    QVector<double> y(100), pointv(100);
    for(unsigned int i=0;i<100;i++)
    {
        y[i]=1-i/50;
        pointv[i]=point;
    }


    customPlot->graph(2)->setPen(QPen(Qt::red));//se le asigna color rojo a la grafica
    customPlot->graph(2)->setData(pointv,y);//se le asignan los vectores en cada eje que contienen la informacion de la grafica
    // crea los labels de los ejes
    //customPlot->xAxis->setLabel("x");
    //customPlot->yAxis->setLabel("y");
    // asigna los rangos en cada eje de la grafica
    customPlot->xAxis->setRange(0, sigSize);
    customPlot->yAxis->setRange(-1, 1);
    customPlot->replot();

}
//******************************************************************************************************

/*
 * grafica la señal
 */

void plotWidget:: graph( QVector<double> y, long Fs)
{
      signal_in=true;// al graficar se pone en verdadero la bandera
      sigSize=y.size(); // tamaño del vector que contiene ls datos de la señal

      QVector<double> x(sigSize); //vector con los datos en el eje x de la señal
      QVector<double> baset(sigSize);
      for(unsigned int i=0;i<sigSize;i++)
      {
          x[i]=i;// se llena el vector x
          baset[i]=i/Fs;
      }


      customPlot->graph(0)->setData(x, y); //se le asignan los vectores en cada eje que contienen la informacion de la grafica

      // crea los labels de los ejes

      //QVector<double> timebase(sigSize);
      //customPlot->xAxis->setLabel("Time");
      //customPlot->yAxis->setLabel("Amplitude");
      customPlot->xAxis->setTickLabels(false);
      customPlot->yAxis->setTickLabels(false);
      // asigna los rangos en cada eje de la grafica
      customPlot->xAxis->setRange(0, sigSize);
      customPlot->yAxis->setRange(-1, 1);
      customPlot->replot();
      this->x = customPlot->size().width()-customPlot->marginLeft()-customPlot->marginRight(); //tamano aproximado en pixeles de la señal graficada
}
//******************************************************************************************************
/*
 * metodo para asignar un color a la grafica de la señal
 */

void plotWidget::setColor(char*color)
{
    customPlot->graph(0)->setPen(QPen(color));
}

void plotWidget::on_playsignal_clicked()
{
    emit play();
}

void plotWidget::on_playsegment_clicked()
{
    emit playsegment();
}

void plotWidget::on_stop_clicked()
{
    emit sstop();
}
