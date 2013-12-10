#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug()<<99;
    set_read_path("C:/Users/Usuario/Documents/UdeA/2013-2/inteligencia/placas/placas/");
    set_save_path("C:/Users/Usuario/Documents/UdeA/2013-2/inteligencia/placas/placas2/");
    qDebug()<<8;
    for(int i=0;i<200;i++)
    {
        save_image(open_image(i,".jpg"),i,".jpg");
        qDebug()<<i;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_save_path(char* path)
{
    save_path=path;
}

void MainWindow::set_read_path(char *path)
{
    read_path=path;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::save_image(cv::Mat src, int index, char *extencion)
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

cv::Mat MainWindow::open_image( int index, char* extencion)
{
    QString path=read_path;

    if(index<10 && index>0)
        path.append("000");
    else if(index<100 && index>=10)
        path.append("00");
    else if(index<1000 && index>=100)
        path.append("0");
    path.append(QString("%1").arg(index));
    path.append(extencion);

    cv::Mat src_peq=cv::imread(path.toStdString().c_str(),0);
    return src_peq;

}
