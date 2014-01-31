/********************************************************************************
** Form generated from reading UI file 'detector.ui'
**
** Created: Wed Mar 13 09:03:08 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTOR_H
#define UI_DETECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Detector
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Detector)
    {
        if (Detector->objectName().isEmpty())
            Detector->setObjectName(QString::fromUtf8("Detector"));
        Detector->resize(777, 340);
        centralWidget = new QWidget(Detector);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 10, 98, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 10, 98, 27));
        Detector->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Detector);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 777, 25));
        Detector->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Detector);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Detector->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Detector);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Detector->setStatusBar(statusBar);

        retranslateUi(Detector);

        QMetaObject::connectSlotsByName(Detector);
    } // setupUi

    void retranslateUi(QMainWindow *Detector)
    {
        Detector->setWindowTitle(QApplication::translate("Detector", "Detector", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Detector", "load", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Detector", "process", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Detector: public Ui_Detector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTOR_H
