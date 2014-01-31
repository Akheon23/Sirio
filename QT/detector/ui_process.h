/********************************************************************************
** Form generated from reading UI file 'process.ui'
**
** Created: Wed Mar 13 09:03:08 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESS_H
#define UI_PROCESS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Process
{
public:
    QDialogButtonBox *buttonBox;
    QRadioButton *type1Button;
    QRadioButton *type2Button;
    QRadioButton *type3Button;
    QRadioButton *type4Button;
    QRadioButton *type5Button;
    QRadioButton *clean;
    QRadioButton *dontclean;
    QSlider *thrslider;
    QSlider *cleanslider;

    void setupUi(QDialog *Process)
    {
        if (Process->objectName().isEmpty())
            Process->setObjectName(QString::fromUtf8("Process"));
        Process->resize(590, 300);
        buttonBox = new QDialogButtonBox(Process);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(400, 260, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        type1Button = new QRadioButton(Process);
        type1Button->setObjectName(QString::fromUtf8("type1Button"));
        type1Button->setGeometry(QRect(20, 10, 116, 22));
        type2Button = new QRadioButton(Process);
        type2Button->setObjectName(QString::fromUtf8("type2Button"));
        type2Button->setGeometry(QRect(20, 40, 116, 22));
        type3Button = new QRadioButton(Process);
        type3Button->setObjectName(QString::fromUtf8("type3Button"));
        type3Button->setGeometry(QRect(20, 70, 116, 22));
        type4Button = new QRadioButton(Process);
        type4Button->setObjectName(QString::fromUtf8("type4Button"));
        type4Button->setGeometry(QRect(20, 100, 116, 22));
        type5Button = new QRadioButton(Process);
        type5Button->setObjectName(QString::fromUtf8("type5Button"));
        type5Button->setGeometry(QRect(20, 130, 116, 22));
        clean = new QRadioButton(Process);
        clean->setObjectName(QString::fromUtf8("clean"));
        clean->setGeometry(QRect(320, 30, 116, 22));
        dontclean = new QRadioButton(Process);
        dontclean->setObjectName(QString::fromUtf8("dontclean"));
        dontclean->setGeometry(QRect(320, 80, 116, 22));
        thrslider = new QSlider(Process);
        thrslider->setObjectName(QString::fromUtf8("thrslider"));
        thrslider->setGeometry(QRect(30, 190, 160, 29));
        thrslider->setOrientation(Qt::Horizontal);
        cleanslider = new QSlider(Process);
        cleanslider->setObjectName(QString::fromUtf8("cleanslider"));
        cleanslider->setGeometry(QRect(30, 240, 160, 29));
        cleanslider->setOrientation(Qt::Horizontal);

        retranslateUi(Process);
        QObject::connect(buttonBox, SIGNAL(accepted()), Process, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Process, SLOT(reject()));

        QMetaObject::connectSlotsByName(Process);
    } // setupUi

    void retranslateUi(QDialog *Process)
    {
        Process->setWindowTitle(QApplication::translate("Process", "Dialog", 0, QApplication::UnicodeUTF8));
        type1Button->setText(QApplication::translate("Process", "method 1", 0, QApplication::UnicodeUTF8));
        type2Button->setText(QApplication::translate("Process", "method 2", 0, QApplication::UnicodeUTF8));
        type3Button->setText(QApplication::translate("Process", "method 3", 0, QApplication::UnicodeUTF8));
        type4Button->setText(QApplication::translate("Process", "method 4", 0, QApplication::UnicodeUTF8));
        type5Button->setText(QApplication::translate("Process", "method 5", 0, QApplication::UnicodeUTF8));
        clean->setText(QApplication::translate("Process", "clean", 0, QApplication::UnicodeUTF8));
        dontclean->setText(QApplication::translate("Process", "don't clean", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Process: public Ui_Process {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESS_H
