/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Sep 2 11:59:43 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "plotwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionProcess;
    QAction *actionSave;
    QAction *actionSave_segment;
    QAction *actionQuit;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionLoad;
    QAction *actionOptions;
    QWidget *centralWidget;
    QPushButton *process;
    QPushButton *options;
    plotWidget *signalPlot;
    plotWidget *cleanPlot;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuHelp;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(681, 475);
        actionProcess = new QAction(MainWindow);
        actionProcess->setObjectName(QString::fromUtf8("actionProcess"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_segment = new QAction(MainWindow);
        actionSave_segment->setObjectName(QString::fromUtf8("actionSave_segment"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        process = new QPushButton(centralWidget);
        process->setObjectName(QString::fromUtf8("process"));
        process->setGeometry(QRect(10, 360, 151, 51));
        process->setCursor(QCursor(Qt::PointingHandCursor));
        options = new QPushButton(centralWidget);
        options->setObjectName(QString::fromUtf8("options"));
        options->setGeometry(QRect(550, 380, 121, 31));
        options->setCursor(QCursor(Qt::PointingHandCursor));
        signalPlot = new plotWidget(centralWidget);
        signalPlot->setObjectName(QString::fromUtf8("signalPlot"));
        signalPlot->setGeometry(QRect(20, 10, 651, 161));
        signalPlot->setCursor(QCursor(Qt::CrossCursor));
        signalPlot->setMouseTracking(true);
        cleanPlot = new plotWidget(centralWidget);
        cleanPlot->setObjectName(QString::fromUtf8("cleanPlot"));
        cleanPlot->setGeometry(QRect(20, 190, 651, 161));
        cleanPlot->setCursor(QCursor(Qt::CrossCursor));
        cleanPlot->setMouseTracking(false);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 681, 25));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuArchivo->addAction(actionLoad);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionOptions);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionProcess);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSave);
        menuArchivo->addAction(actionSave_segment);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionQuit);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GNS", 0, QApplication::UnicodeUTF8));
        actionProcess->setText(QApplication::translate("MainWindow", "Process", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSave_segment->setText(QApplication::translate("MainWindow", "Save segment", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q, Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        actionLoad->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        process->setText(QApplication::translate("MainWindow", "process", 0, QApplication::UnicodeUTF8));
        options->setText(QApplication::translate("MainWindow", "options", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
