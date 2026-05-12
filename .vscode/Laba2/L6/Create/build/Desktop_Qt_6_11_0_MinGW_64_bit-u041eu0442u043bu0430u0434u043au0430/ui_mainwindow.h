/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineName;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineDescription;
    QLineEdit *lineCoef;
    QLineEdit *lineType;
    QPushButton *btnLoadTxt;
    QPushButton *btnSaveJson;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 394);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 71, 41));
        lineName = new QLineEdit(centralwidget);
        lineName->setObjectName("lineName");
        lineName->setGeometry(QRect(210, 10, 171, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 71, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 130, 131, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 190, 111, 41));
        lineDescription = new QLineEdit(centralwidget);
        lineDescription->setObjectName("lineDescription");
        lineDescription->setGeometry(QRect(210, 70, 171, 41));
        lineCoef = new QLineEdit(centralwidget);
        lineCoef->setObjectName("lineCoef");
        lineCoef->setGeometry(QRect(210, 130, 171, 41));
        lineType = new QLineEdit(centralwidget);
        lineType->setObjectName("lineType");
        lineType->setGeometry(QRect(210, 190, 171, 41));
        btnLoadTxt = new QPushButton(centralwidget);
        btnLoadTxt->setObjectName("btnLoadTxt");
        btnLoadTxt->setGeometry(QRect(460, 30, 301, 101));
        btnSaveJson = new QPushButton(centralwidget);
        btnSaveJson->setObjectName("btnSaveJson");
        btnSaveJson->setGeometry(QRect(460, 190, 301, 101));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\267\320\260\321\211\320\270\321\202\321\213", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\267\320\260\321\211\320\270\321\202\321\213", nullptr));
        btnLoadTxt->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 TXT", nullptr));
        btnSaveJson->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 JSON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
