/********************************************************************************
** Form generated from reading UI file 'featureextractor.ui'
**
** Created: Mon Nov 18 16:16:18 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEATUREEXTRACTOR_H
#define UI_FEATUREEXTRACTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FeatureExtractor
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FeatureExtractor)
    {
        if (FeatureExtractor->objectName().isEmpty())
            FeatureExtractor->setObjectName(QString::fromUtf8("FeatureExtractor"));
        FeatureExtractor->resize(400, 300);
        menuBar = new QMenuBar(FeatureExtractor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        FeatureExtractor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FeatureExtractor);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        FeatureExtractor->addToolBar(mainToolBar);
        centralWidget = new QWidget(FeatureExtractor);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        FeatureExtractor->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FeatureExtractor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FeatureExtractor->setStatusBar(statusBar);

        retranslateUi(FeatureExtractor);

        QMetaObject::connectSlotsByName(FeatureExtractor);
    } // setupUi

    void retranslateUi(QMainWindow *FeatureExtractor)
    {
        FeatureExtractor->setWindowTitle(QApplication::translate("FeatureExtractor", "FeatureExtractor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FeatureExtractor: public Ui_FeatureExtractor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEATUREEXTRACTOR_H
