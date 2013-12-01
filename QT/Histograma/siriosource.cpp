#include "siriosource.h"
#include "ui_siriosource.h"

SirioSource::SirioSource(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SirioSource)
{
    ui->setupUi(this);
}

SirioSource::~SirioSource()
{
    delete ui;
}

void SirioSource::on_pushButton_clicked()
{
    src=cvLoadImage("/home/lex/Cv/Images/video_screenshot_21.07.2013.png");
    src2=cvLoadImage("/home/lex/Cv/Images/video_screenshot_21.07.201322.png");
    src3=cvLoadImage("/home/lex/Cv/Images/muestra_placa.png");

    resultado= Halley.sHistPathMatch(src,src3);


    Cannis.showInLabel( src3,"label",this);
    cvShowImage("resultado",resultado);


}

void SirioSource::on_pushButton_2_clicked()
{
    resultadocolor=perseid.sGetColorMask(src,0,40,60,40,150,150);
    cvShowImage("resultado2",resultadocolor);
}
