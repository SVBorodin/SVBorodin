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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_login;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *addressEdit;
    QLineEdit *portEdit;
    QLineEdit *idEdit;
    QPushButton *connectButton;
    QWidget *page_game;
    QLabel *weatherLabel;
    QPushButton *upButton;
    QPushButton *leftButton;
    QPushButton *downButton;
    QPushButton *rightButton;
    QPushButton *imitationButton;
    QComboBox *colorComboBox;
    QLabel *label_4;
    QPushButton *musicToggle;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(680, 480);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 10, 660, 440));
        page_login = new QWidget();
        page_login->setObjectName("page_login");
        label = new QLabel(page_login);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 110, 61, 21));
        label_2 = new QLabel(page_login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 150, 61, 21));
        label_3 = new QLabel(page_login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(150, 200, 61, 21));
        addressEdit = new QLineEdit(page_login);
        addressEdit->setObjectName("addressEdit");
        addressEdit->setGeometry(QRect(230, 110, 141, 24));
        portEdit = new QLineEdit(page_login);
        portEdit->setObjectName("portEdit");
        portEdit->setGeometry(QRect(230, 150, 141, 24));
        idEdit = new QLineEdit(page_login);
        idEdit->setObjectName("idEdit");
        idEdit->setGeometry(QRect(230, 200, 141, 24));
        connectButton = new QPushButton(page_login);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(230, 250, 141, 32));
        stackedWidget->addWidget(page_login);
        page_game = new QWidget();
        page_game->setObjectName("page_game");
        weatherLabel = new QLabel(page_game);
        weatherLabel->setObjectName("weatherLabel");
        weatherLabel->setGeometry(QRect(450, 20, 200, 50));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        weatherLabel->setFont(font);
        upButton = new QPushButton(page_game);
        upButton->setObjectName("upButton");
        upButton->setGeometry(QRect(520, 220, 41, 41));
        leftButton = new QPushButton(page_game);
        leftButton->setObjectName("leftButton");
        leftButton->setGeometry(QRect(475, 265, 41, 41));
        downButton = new QPushButton(page_game);
        downButton->setObjectName("downButton");
        downButton->setGeometry(QRect(520, 265, 41, 41));
        rightButton = new QPushButton(page_game);
        rightButton->setObjectName("rightButton");
        rightButton->setGeometry(QRect(565, 265, 41, 41));
        imitationButton = new QPushButton(page_game);
        imitationButton->setObjectName("imitationButton");
        imitationButton->setGeometry(QRect(475, 315, 131, 31));
        colorComboBox = new QComboBox(page_game);
        colorComboBox->setObjectName("colorComboBox");
        colorComboBox->setGeometry(QRect(500, 380, 111, 24));
        label_4 = new QLabel(page_game);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(440, 380, 51, 21));
        musicToggle = new QPushButton(page_game);
        musicToggle->setObjectName("musicToggle");
        musicToggle->setGeometry(QRect(440, 140, 171, 31));
        stackedWidget->addWidget(page_game);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\273\320\270\320\265\320\275\321\202-\320\241\320\265\321\200\320\262\320\265\321\200", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\271 ID", nullptr));
        addressEdit->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        portEdit->setText(QCoreApplication::translate("MainWindow", "12345", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\320\272\321\202", nullptr));
        weatherLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\263\320\276\320\264\320\260:", nullptr));
        upButton->setText(QCoreApplication::translate("MainWindow", "\342\226\262", nullptr));
        leftButton->setText(QCoreApplication::translate("MainWindow", "\342\227\200", nullptr));
        downButton->setText(QCoreApplication::translate("MainWindow", "\342\226\274", nullptr));
        rightButton->setText(QCoreApplication::translate("MainWindow", "\342\226\266", nullptr));
        imitationButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\320\270\321\202\320\260\321\206\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202:", nullptr));
        musicToggle->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\274\321\203\320\267\321\213\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
