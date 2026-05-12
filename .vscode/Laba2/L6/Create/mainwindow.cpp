#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLoadTxt_clicked()
{
    QString path = QFileDialog::getOpenFileName(
        this,
        "Открыть txt",
        "",
        "TXT files (*.txt)"
        );

    if(path.isEmpty())
        return;

    QFile file(path);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    ui->lineName->setText(in.readLine());
    ui->lineDescription->setText(in.readLine());
    ui->lineCoef->setText(in.readLine());
    ui->lineType->setText(in.readLine());

    file.close();
}

void MainWindow::on_btnSaveJson_clicked()
{
    QString name = ui->lineName->text();
    QString description = ui->lineDescription->text();
    QString coef = ui->lineCoef->text();
    QString type = ui->lineType->text();

    QString path = QFileDialog::getSaveFileName(
        this,
        "Сохранить json",
        "",
        "JSON (*.json)"
        );

    if(path.isEmpty())
        return;

    QJsonObject shield;

    shield["name"] = name;
    shield["description"] = description;
    shield["protectionCoef"] = coef.toDouble();
    shield["protectionType"] = type;

    QJsonArray array;

    QFile file(path);

    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly))
        {
            QByteArray data = file.readAll();

            QJsonDocument doc = QJsonDocument::fromJson(data);

            if(doc.isArray())
                array = doc.array();

            file.close();
        }
    }

    array.append(shield);

    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    QJsonDocument doc(array);

    file.write(doc.toJson());

    file.close();

    QMessageBox::information(this, "Успех", "Объект сохранен");
}