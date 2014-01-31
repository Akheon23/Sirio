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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "option.h"
#include "QFileDialog"

#include<QMovie>
#include<QLabel>

//**********************************************************************************************************
/*
 * Constructor por defecto
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Inicializar la interfaz grafica
    type=4;
    cleanMod=5;
    thrMod=1;
    process=new Procesamiento(); // Reservar memoria dinamica

    playFlag=false;
    loadflag=false;
    processflag=false;


    connect(ui->cleanPlot,SIGNAL(play()),this,SLOT(play_clean_signal()));
    connect(ui->cleanPlot,SIGNAL(playsegment()),this,SLOT(play_clean_segment()));
    connect(ui->cleanPlot,SIGNAL(sstop()),this,SLOT(stopbutton()));


    connect(ui->signalPlot,SIGNAL(play()),this,SLOT(play_signal()));
    connect(ui->signalPlot,SIGNAL(playsegment()),this,SLOT(play_segment()));
    connect(ui->signalPlot,SIGNAL(sstop()),this,SLOT(stopbutton()));


}
//************************************************************************************************************
/*
 * Destructor
 */

MainWindow::~MainWindow()
{
    // Limpiar memoria dinamica
    delete process;
    delete ui;
}

//***********************************************************************************************************
/*
 * Slot que se llama al hacer click en el boton de reproducir la senal original
 */

void MainWindow::play_signal()
{
    if (!playFlag && loadflag){ // Si no se esta reproduciendo y si ya se cargo la senal original

        Procesamiento* playProcess = new Procesamiento(process); // Crear una copia del objeto de procesamiento
        QThread* thread = new QThread(); // Crear un nuevo hilo
        // Mover la copia del objeto de procesamiento al nuevo hilo para no bloquear la interfaz grafica al reproducir
        playProcess->moveToThread(thread);

        //connect(process, SIGNAL(error(QString)), this, SLOT(errorString(QString)));

        // Conectar senal de inicio del hilo con la senal de proceso para reproducir
        connect(thread, SIGNAL(started()), playProcess, SLOT(playSignal()));

        // Conectar senal de finalizar la reproduccion con el cierre del hilo y con el slot de finalizacion de reproduccion de mainwindow
        connect(playProcess, SIGNAL(finished()), thread, SLOT(quit()));
        connect(playProcess, SIGNAL(finished()), this, SLOT(playFinish()));

        // Al recibir la senal stop indicarle a procesamiento que detenga la reproduccion
        // connect(this, SIGNAL(stop()), thread,SLOT(quit()));
        connect(this,SIGNAL(stop()),playProcess,SLOT(stop()));

        // Al finalizar la reproduccion programar la desctruccion de los objetos creados
        connect(playProcess, SIGNAL(finished()), playProcess, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));


        playFlag=true; // Indicar que se esta reproduciendo

        thread->start(); // Iniciar el hilo y la reproduccion

    }


}


//**************************************************************************************************************************
/*
 * Slot que llama al hacer click en el boton de limpiar la senal
 */

void MainWindow::on_process_clicked()
{
    processflag=false;
    if(loadflag)
    {
        double iRatio,fRatio;

        if(ui->signalPlot->getIRatio() <= ui->signalPlot->getFRatio())
        {
            iRatio=ui->signalPlot->getIRatio();
            fRatio=ui->signalPlot->getFRatio();
        }
        else
        {
            iRatio=ui->signalPlot->getFRatio();
            fRatio=ui->signalPlot->getIRatio();
        }

        process->setSegment(iRatio,fRatio);

        process->cleanSignal(cleanMod,thrMod,type);
        ui->cleanPlot->setColor("green");

        ui->cleanPlot->graph(process->getClean(),process->getFs());


        processflag=true;
    }
}

//******************************************************************************************************************************

/*
 * Slot que llama al hacer click en el boton de reproducir la senal limpia
 */


void MainWindow::play_clean_signal()
{
    if(loadflag && processflag && !playFlag) // Si no se esta reproduciendo y si ya se cargo la senal original
    {
        Procesamiento* playProcess = new Procesamiento(process); // Crear una copia del objeto de procesamiento
        QThread* thread = new QThread(); // Crear un nuevo hilo
        // Mover la copia del objeto de procesamiento al nuevo hilo para no bloquear la interfaz grafica al reproducir
        playProcess->moveToThread(thread);

        //connect(process, SIGNAL(error(QString)), this, SLOT(errorString(QString)));

        // Conectar senal de inicio del hilo con la senal de proceso para reproducir
        connect(thread, SIGNAL(started()), playProcess, SLOT(playClean()));

        // Conectar senal de finalizar la reproduccion con el cierre del hilo y con el slot de finalizacion de reproduccion de mainwindow
        connect(playProcess, SIGNAL(finished()), thread, SLOT(quit()));
        connect(playProcess, SIGNAL(finished()), this, SLOT(playFinish()));

        // Al recibir la senal stop finalizar el proceso para detener la reproduccion
        // connect(this, SIGNAL(stop()), thread,SLOT(quit()));
        connect(this,SIGNAL(stop()),playProcess,SLOT(stop()));

        // Al finalizar programar la desctruccion de los objetos creados
        connect(playProcess, SIGNAL(finished()), playProcess, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

        playFlag=true; // Indicar que se esta reproduciendo

        thread->start(); // Iniciar el hilo y la reproduccion
    }
}

//**********************************************************************************************************************
/*
 * Slot que se llama al hacer click en el boton de opciones
 */

void MainWindow::on_options_clicked()
{
    this->options();
}

//**********************************************************************************************************************

/*
 * Slot que se llama al hacer click en el boton de detener la reproduccion
 */

void MainWindow::stopbutton()
{
    emit stop(); // Emitir la senal para terminar la reproduccion
}

//**********************************************************************************************************************
/*
 * Slot que se llama al terminar la reproduccion de alguna senal o fragmento
 */
void MainWindow::playFinish()
{
    playFlag=false; // Indicar que ya no se esta reproduciendo
}

void MainWindow::options()
{
    option *Myoption = new option(); // Crear un objeto de cuadro de dialogo opciones

    // Llevar los valores actuales de las opciones al cuadro de dialogo de opciones
    Myoption->setCleanMod(cleanMod);
    Myoption->setThrMod(thrMod);
    Myoption->setType(type);

    if(Myoption->exec() == QDialog::Accepted ) // Si el usuario hizo aceptar (OK) en el cuadro de dialogo
    {
        // Actualizar los valores de las opciones
        type=Myoption->getType();
        cleanMod=Myoption->getCleanMod();
        thrMod=Myoption->getThrMod();
    }
}

//**********************************************************************************************************************

/*
 * Slot que se llama al hacer click en el boton de reproducir un fragmento de la senal original
 */

void MainWindow::play_segment()
{
    if(loadflag &&!playFlag){ // Si ya se cargo la senal y si no se esta reproduciendo
        // Obtener la fraccion de la senal que el usuario selecciono para reproducir
        double iRatio, fRatio;
        if(ui->signalPlot->getIRatio() <= ui->signalPlot->getFRatio())
        {
            iRatio=ui->signalPlot->getIRatio();
            fRatio=ui->signalPlot->getFRatio();
        }
        else
        {
            iRatio=ui->signalPlot->getFRatio();
            fRatio=ui->signalPlot->getIRatio();
        }

        process->setSegment(iRatio,fRatio); // Llevar las fracciones al objeto de procesamiento

        Procesamiento* playProcess = new Procesamiento(process); // Crear una copia del objeto de procesamiento
        QThread* thread = new QThread(); // Crear un nuevo hilo
        // Mover la copia del objeto de procesamiento al nuevo hilo para no bloquear la interfaz grafica al reproducir
        playProcess->moveToThread(thread);

        //connect(process, SIGNAL(error(QString)), this, SLOT(errorString(QString)));

        // Conectar senal de inicio del hilo con senal de proceso
        connect(thread, SIGNAL(started()), playProcess, SLOT(playSegment()));

        // Conectar senal de finalizar la reproduccion con el cierre del hilo y con el slot de finalizacion de reproduccion de mainwindow
        connect(playProcess, SIGNAL(finished()), thread, SLOT(quit()));
        connect(playProcess, SIGNAL(finished()), this, SLOT(playFinish()));

        // Al recibir la senal stop finalizar el proceso para detener la reproduccion
        // connect(this, SIGNAL(stop()), thread,SLOT(quit()));
        connect(this,SIGNAL(stop()),playProcess,SLOT(stop()));

        // Al finalizar la reproduccion programar la desctruccion de los objetos creados
        connect(playProcess, SIGNAL(finished()), playProcess, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

        playFlag=true; // Indicar que se esta reproduciendo una senal

        thread->start(); // Iniciar el hilo y la reproduccion
    }
}
//************************************************************************************************************
/*
 * Slot que se llama al hacer click en el boton de reproducir un fragmento de la senal limpia
 */

void MainWindow::play_clean_segment()
{
    if(loadflag &&!playFlag && processflag) // Si ya se cargo la senal, y se limpio y si no se esta reproduciendo
    {
        // Obtener la fraccion de la senal que el usuario selecciono para reproducir
        double iRatio, fRatio;
        if(ui->cleanPlot->getIRatio() <= ui->cleanPlot->getFRatio())
        {
            iRatio=ui->cleanPlot->getIRatio();
            fRatio=ui->cleanPlot->getFRatio();
        }
        else
        {
            iRatio=ui->cleanPlot->getFRatio();
            fRatio=ui->cleanPlot->getIRatio();
        }

        process->setSegment(iRatio,fRatio); // Llevar las fracciones al objeto de procesamiento


        Procesamiento* playProcess = new Procesamiento(process); // Crear una copia del objeto de procesamiento
        QThread* thread = new QThread(); // Crear un nuevo hilo
        // Mover la copia del objeto de procesamiento al nuevo hilo para no bloquear la interfaz grafica
        playProcess->moveToThread(thread);

        //connect(process, SIGNAL(error(QString)), this, SLOT(errorString(QString)));

        // Conectar senal de inicio del hilo con senal de proceso de reproduccion
        connect(thread, SIGNAL(started()), playProcess, SLOT(playCleanSegment()));

        // Conectar senal de finalizar la reproduccion con el cierre del hilo y con el slot de finalizacion de reproduccion de mainwindow
        connect(playProcess, SIGNAL(finished()), thread, SLOT(quit()));
        connect(playProcess, SIGNAL(finished()), this, SLOT(playFinish()));

        // Al recibir la senal stop finalizar el proceso para detener la reproduccion
        // connect(this, SIGNAL(stop()), thread,SLOT(quit()));
        connect(this,SIGNAL(stop()),playProcess,SLOT(stop()));

        // Al finalizar la reproduccion programar la desctruccion de los objetos creados
        connect(playProcess, SIGNAL(finished()), playProcess, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

        playFlag=true; // Indicar que se esta reproduciendo una senal

        thread->start(); // Iniciar el hilo y la reproduccion
    }
}

//*************************************************************************************************
/*
 * Slot que se llama al hacer click en el boton de reproducir un fragmento de la senal original
 */
/*
void MainWindow::on_stopButton_2_clicked()
{
     emit stop(); // Emitir la senal para terminar la reproduccion
}
*/

void MainWindow::on_actionProcess_triggered()
{
    this->on_process_clicked();
}

//*********************************************************************************************************************************
/*
 * Slot que se llama al hacer click en la opcion de cargar senal en el menu archivo
 */

void MainWindow::on_actionLoad_triggered()
{
    // Obtener la ruta y el nombre de archivo por medio de un cuadro de dialogo
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.wav)"));

    char* to_open;

    to_open=fileName.toAscii().data();
    // Indicarle al objeto de procesamiento que cargue la senal
    process->openSignal(to_open);

    // Dibujar senal
    //ui->textBrowser->setDocumentTitle(fileName);
    ui->signalPlot->graph(process->getSignal(), process->getFs());
    loadflag=true; // Indicar que ya se cargo la senal
}

//****************************************************************************************************************************
/*
 * Slot que se llama al hacer click en la opcion de guardar la senal limpia en el menu archivo
 */

void MainWindow::on_actionSave_triggered()
{
    if(loadflag && processflag) // Si ya se tiene la senal cargada y limpia
    {
        // Obtener el nombre para guardar la senal por medio de un cuadro de dialogo
        QString fileName = QFileDialog::getSaveFileName(this,"","","Audio(*.wav)");
        process->saveClean(fileName); // Guardar la senal por medio del objeto de proecesamiento
    }
}


//*******************************************************************************************************************************
/*
 * Slot que se llama al hacer click en la opcion de guardar un segmento de la senal limpia en el menu
 */

void MainWindow::on_actionSave_segment_triggered()
{
    if(processflag) // Si ya se tiene la senal cargada y limpia
    {
        // Obtener la fraccion de la senal que el usuario selecciono para guardar
        double iRatio,fRatio;
        if(ui->signalPlot->getIRatio() <= ui->signalPlot->getFRatio())
        {
            iRatio=ui->cleanPlot->getIRatio();
            fRatio=ui->cleanPlot->getFRatio();
        }
        else
        {
            iRatio=ui->cleanPlot->getFRatio();
            fRatio=ui->cleanPlot->getIRatio();
        }
        // Obtener el nombre para guardar la senal por medio de un cuadro de dialogo
        QString fileName = QFileDialog::getSaveFileName(this,"","","Audio(*.wav)");
        process->saveSegment(iRatio,fRatio,fileName); // Guardar la senal por medio del objeto de proecesamiento
    }
}

void MainWindow::on_actionOptions_triggered()
{
    this->options();
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->exit(0);
}
