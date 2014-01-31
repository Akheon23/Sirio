#ifndef PROCESS_H
#define PROCESS_H

#include <QDialog>

namespace Ui {
class Process;
}

class Process : public QDialog
{
    Q_OBJECT
    
public:
    explicit Process(QWidget *parent = 0);
    ~Process();
    char getType();
    void setType(char typeNow);
    int getThrMod();
    void setThrMod(int thrMod);
    int getCleanMod();
    void setCleanMod(int cleanMod);

private:
    Ui::Process *ui;
};

#endif // PROCESS_H
