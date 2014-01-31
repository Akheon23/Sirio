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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

#include <QVector>
#include <QThread>
#include "procesamiento.h"

#include <QTranslator>


namespace Ui {
class MainWindow;
}

/*
 * Esta clase es la ventana principal del programa
 * La mayoria de los slots se llaman al hacer click en alguno de los botones
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    //void on_original_clicked();
    //void on_load_clicked();
    void on_process_clicked();
    //void on_clean_clicked();
    //void on_save_clicked();
    void on_options_clicked();
    //void on_stopButton_clicked();
    void playFinish();

    void options();

    void play_clean_signal();
    void play_clean_segment();
    void stopbutton();
    void play_signal();
    void play_segment();

    //void on_segmentButton_clicked();
    //void on_save_segment_clicked();
    //void on_cleanSegment_clicked();
    //void on_stopButton_2_clicked();

    void on_actionProcess_triggered();
    void on_actionLoad_triggered();
    void on_actionSave_triggered();
    void on_actionSave_segment_triggered();

    void on_actionOptions_triggered();

    void on_actionQuit_triggered();

signals:
    void stop();


private:
    Ui::MainWindow *ui; // Interfaz grafica

    QString fileName; // Ruta y nombre del archivo
    char type; // Tipo de SS a utilizar
    int cleanMod; // Parametro de limpieza
    int thrMod; // Parametro de umbral de ruido
    Procesamiento* process; // Objeto que se encarga del procesamiento (cargar, reproduccion, limpieza, guardar)

    bool playFlag,loadflag,processflag; // Banderas de estados
};

#endif // MAINWINDOW_H
