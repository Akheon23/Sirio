#ifndef PROCESS_H
#define PROCESS_H

#include <QMainWindow>

namespace Ui {
class Process;
}

class Process : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Process(QWidget *parent = 0);
    ~Process();
    
private:
    Ui::Process *ui;
};

#endif // PROCESS_H
