#include "detector.h"
#include "ui_detector.h"

Detector::Detector(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Detector)
{
    ui->setupUi(this);
}

Detector::~Detector()
{
    delete ui;
}

void Detector::on_pushButton_2_clicked()
{
    Process *Myprocess= new Process;

    //Myprocess->setCleanMod(/*cleanMod*/);
    //Myprocess->setThrMod(/*thrMod*/);
    //Myprocess->setType(/*type*/);

    if(Myprocess->exec() == QDialog::Accepted ) // Si el usuario hizo aceptar (OK) en el cuadro de dialogo
    {
        // Actualizar los valores de las opciones
        //type=Myprocess->getType();
        //cleanMod=Myprocess->getCleanMod();
        //thrMod=Myprocess->getThrMod();

    }
    else if (Myprocess->exec() == QDialog::Rejected )
    {

    }
}
