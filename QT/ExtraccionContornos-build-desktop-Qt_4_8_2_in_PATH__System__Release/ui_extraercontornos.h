/********************************************************************************
** Form generated from reading UI file 'extraercontornos.ui'
**
** Created: Mon Dec 9 23:32:33 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTRAERCONTORNOS_H
#define UI_EXTRAERCONTORNOS_H

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

class Ui_ExtraerContornos
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExtraerContornos)
    {
        if (ExtraerContornos->objectName().isEmpty())
            ExtraerContornos->setObjectName(QString::fromUtf8("ExtraerContornos"));
        ExtraerContornos->resize(234, 189);
        centralWidget = new QWidget(ExtraerContornos);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 30, 111, 51));
        ExtraerContornos->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ExtraerContornos);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 234, 29));
        ExtraerContornos->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExtraerContornos);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ExtraerContornos->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ExtraerContornos);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ExtraerContornos->setStatusBar(statusBar);

        retranslateUi(ExtraerContornos);

        QMetaObject::connectSlotsByName(ExtraerContornos);
    } // setupUi

    void retranslateUi(QMainWindow *ExtraerContornos)
    {
        ExtraerContornos->setWindowTitle(QApplication::translate("ExtraerContornos", "ExtraerContornos", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ExtraerContornos", "Segmentar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExtraerContornos: public Ui_ExtraerContornos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRAERCONTORNOS_H
