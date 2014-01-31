/********************************************************************************
** Form generated from reading UI file 'alineacion.ui'
**
** Created: Thu Jan 23 18:45:38 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALINEACION_H
#define UI_ALINEACION_H

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

class Ui_Alineacion
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Alineacion)
    {
        if (Alineacion->objectName().isEmpty())
            Alineacion->setObjectName(QString::fromUtf8("Alineacion"));
        Alineacion->resize(432, 325);
        centralWidget = new QWidget(Alineacion);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 180, 102, 28));
        Alineacion->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Alineacion);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 432, 26));
        Alineacion->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Alineacion);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Alineacion->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Alineacion);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Alineacion->setStatusBar(statusBar);

        retranslateUi(Alineacion);

        QMetaObject::connectSlotsByName(Alineacion);
    } // setupUi

    void retranslateUi(QMainWindow *Alineacion)
    {
        Alineacion->setWindowTitle(QApplication::translate("Alineacion", "Alineacion", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Alineacion", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Alineacion: public Ui_Alineacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALINEACION_H
