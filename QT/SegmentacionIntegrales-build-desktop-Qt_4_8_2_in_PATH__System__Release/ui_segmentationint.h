/********************************************************************************
** Form generated from reading UI file 'segmentationint.ui'
**
** Created: Mon Dec 9 20:02:01 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEGMENTATIONINT_H
#define UI_SEGMENTATIONINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SegmentationINT
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SegmentationINT)
    {
        if (SegmentationINT->objectName().isEmpty())
            SegmentationINT->setObjectName(QString::fromUtf8("SegmentationINT"));
        SegmentationINT->resize(400, 300);
        centralWidget = new QWidget(SegmentationINT);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 141, 81));
        label->setFrameShape(QFrame::WinPanel);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 140, 95, 31));
        SegmentationINT->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SegmentationINT);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 29));
        SegmentationINT->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SegmentationINT);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SegmentationINT->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SegmentationINT);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SegmentationINT->setStatusBar(statusBar);

        retranslateUi(SegmentationINT);

        QMetaObject::connectSlotsByName(SegmentationINT);
    } // setupUi

    void retranslateUi(QMainWindow *SegmentationINT)
    {
        SegmentationINT->setWindowTitle(QApplication::translate("SegmentationINT", "SegmentationINT", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton->setText(QApplication::translate("SegmentationINT", "Imagen", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SegmentationINT: public Ui_SegmentationINT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEGMENTATIONINT_H
