#include "featureextractor.h"
#include "ui_featureextractor.h"

FeatureExtractor::FeatureExtractor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FeatureExtractor)
{
    ui->setupUi(this);
}

FeatureExtractor::~FeatureExtractor()
{
    delete ui;
}
