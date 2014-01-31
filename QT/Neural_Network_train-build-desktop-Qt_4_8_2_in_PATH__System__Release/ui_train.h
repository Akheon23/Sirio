/********************************************************************************
** Form generated from reading UI file 'train.ui'
**
** Created: Thu Jan 30 21:15:30 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAIN_H
#define UI_TRAIN_H

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

class Ui_Train
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Train)
    {
        if (Train->objectName().isEmpty())
            Train->setObjectName(QString::fromUtf8("Train"));
        Train->resize(400, 300);
        centralWidget = new QWidget(Train);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 70, 102, 28));
        Train->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Train);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        Train->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Train);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Train->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Train);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Train->setStatusBar(statusBar);

        retranslateUi(Train);

        QMetaObject::connectSlotsByName(Train);
    } // setupUi

    void retranslateUi(QMainWindow *Train)
    {
        Train->setWindowTitle(QApplication::translate("Train", "Train", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Train", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Train: public Ui_Train {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAIN_H
