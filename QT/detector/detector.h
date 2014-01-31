#ifndef DETECTOR_H
#define DETECTOR_H

#include <QMainWindow>
#include <process.h>
#include<QMessageBox>

namespace Ui {
class Detector;
}

class Detector : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Detector(QWidget *parent = 0);
    ~Detector();
    
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Detector *ui;
};

#endif // DETECTOR_H
