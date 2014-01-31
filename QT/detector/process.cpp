#include "process.h"
#include "ui_process.h"

Process::Process(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Process)
{
    ui->setupUi(this);
}

//**********************************************************************************************
/*
 * Funcion para inicializar el valor del parametro de umbral
 */

void Process::setThrMod(int thrMod)
{
    ui->thrslider->setValue(thrMod);
}

//****************************************************************************************************
/*
 * Devolver el valor del parametro de limpieza
 */
int Process::getCleanMod()
{
    return ui->cleanslider->value();
}

//**********************************************************************************************
/*
 * Funcion para inicializar el valor del parametro de de limpieza
 */

void Process::setCleanMod(int cleanMod)
{
    ui->cleanslider->setValue(cleanMod);
}

//*******************************************************************************************************

Process::~Process()
{
    delete ui;
}

void Process::setType(char typeNow)
{
    switch(typeNow){
    case 1:
        ui->type1Button->click();
        break;
    case 2:
        ui->type2Button->click();
        break;
    case 3:
        ui->type3Button->click();
        break;
    case 4:
        ui->type4Button->click();
        break;
    case 5:
        ui->type5Button->click();
        break;
    };
}

//***********************************************************************************************
/*
 * Devolver el valor del parametro de umbral
 */
int Process::getThrMod()
{
    return ui->thrslider->value();
}
