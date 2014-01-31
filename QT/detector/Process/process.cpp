#include "process.h"
#include "ui_process.h"

Process::Process(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Process)
{
    ui->setupUi(this);
}

Process::~Process()
{
    delete ui;
}
