#include "process.h"
#include "ui_process.h"

Process::Process(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Process)
{
    ui->setupUi(this);
}

Process::~Process()
{
    delete ui;
}
