/********************************************************************************
** Form generated from reading UI file 'siriosource.ui'
**
** Created: Thu Aug 1 09:30:31 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIRIOSOURCE_H
#define UI_SIRIOSOURCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SirioSource
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLCDNumber *lcdNumber;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SirioSource)
    {
        if (SirioSource->objectName().isEmpty())
            SirioSource->setObjectName(QString::fromUtf8("SirioSource"));
        SirioSource->resize(793, 549);
        centralWidget = new QWidget(SirioSource);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 281, 351));
        label->setFrameShape(QFrame::WinPanel);
        label->setScaledContents(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 410, 91, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 410, 98, 27));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(520, 40, 191, 41));
        SirioSource->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SirioSource);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 793, 25));
        SirioSource->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SirioSource);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SirioSource->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SirioSource);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SirioSource->setStatusBar(statusBar);

        retranslateUi(SirioSource);

        QMetaObject::connectSlotsByName(SirioSource);
    } // setupUi

    void retranslateUi(QMainWindow *SirioSource)
    {
        SirioSource->setWindowTitle(QApplication::translate("SirioSource", "SirioSource", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton->setText(QApplication::translate("SirioSource", "Imagen", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("SirioSource", "Calcular hist", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SirioSource: public Ui_SirioSource {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIRIOSOURCE_H
