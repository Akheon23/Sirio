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

#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>
#include <QMouseEvent>


#include "qcustomplot.h"

namespace Ui {
class plotWidget;
}

/*
 * Esta clase es una ventana auxiliar del programa
 * Es usada para mostrar la reprecentacion grafica de las señales de audio
 * Tabién hace posible la interaccion con el mouse
 */

class plotWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit plotWidget(QWidget *parent = 0);
    ~plotWidget();

    double getIRatio(){return iRatio;}
    double getFRatio(){return fRatio;}
    void graph( QVector<double> y, long Fs );
    long distance(long point);
    void graphPoint_1( double point);
    void graphPoint_2( double point);
    void setColor(char*color);


private slots:
    void mousePressEvent ( QMouseEvent * event );

    void on_playsignal_clicked();
    void on_playsegment_clicked();

    void on_stop_clicked();

signals:
    void play();
    void playsegment();
    void sstop();

private:
    Ui::plotWidget *ui;
    double iRatio, fRatio;
    unsigned int x;
    unsigned long sigSize;
    bool signal_in,first;
    QCustomPlot *customPlot;
};

#endif // PLOTWIDGET_H
