/********************************************************************************
** Form generated from reading UI file 'track.ui'
**
** Created: Mon Nov 11 09:54:09 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACK_H
#define UI_TRACK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Track
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Track)
    {
        if (Track->objectName().isEmpty())
            Track->setObjectName(QString::fromUtf8("Track"));
        Track->resize(713, 518);
        centralWidget = new QWidget(Track);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 341, 311));
        label->setFrameShape(QFrame::WinPanel);
        label->setScaledContents(true);
        Track->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Track);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 713, 29));
        Track->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Track);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Track->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Track);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Track->setStatusBar(statusBar);

        retranslateUi(Track);

        QMetaObject::connectSlotsByName(Track);
    } // setupUi

    void retranslateUi(QMainWindow *Track)
    {
        Track->setWindowTitle(QApplication::translate("Track", "Track", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Track: public Ui_Track {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACK_H
