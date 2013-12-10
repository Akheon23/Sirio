/********************************************************************************
** Form generated from reading UI file 'lettersegmentation.ui'
**
** Created: Sun Dec 8 13:16:34 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LETTERSEGMENTATION_H
#define UI_LETTERSEGMENTATION_H

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

class Ui_LetterSegmentation
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LetterSegmentation)
    {
        if (LetterSegmentation->objectName().isEmpty())
            LetterSegmentation->setObjectName(QString::fromUtf8("LetterSegmentation"));
        LetterSegmentation->resize(400, 300);
        centralWidget = new QWidget(LetterSegmentation);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 130, 95, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 121, 81));
        label->setFrameShape(QFrame::WinPanel);
        label->setScaledContents(true);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 130, 95, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 40, 121, 81));
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setScaledContents(true);
        LetterSegmentation->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LetterSegmentation);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 29));
        LetterSegmentation->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LetterSegmentation);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LetterSegmentation->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LetterSegmentation);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LetterSegmentation->setStatusBar(statusBar);

        retranslateUi(LetterSegmentation);

        QMetaObject::connectSlotsByName(LetterSegmentation);
    } // setupUi

    void retranslateUi(QMainWindow *LetterSegmentation)
    {
        LetterSegmentation->setWindowTitle(QApplication::translate("LetterSegmentation", "LetterSegmentation", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LetterSegmentation", "Imagen", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton_2->setText(QApplication::translate("LetterSegmentation", "Segmentar", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LetterSegmentation: public Ui_LetterSegmentation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LETTERSEGMENTATION_H
