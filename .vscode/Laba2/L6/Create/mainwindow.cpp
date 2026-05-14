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
    QString path = QFileDialog::getOpenFileName(this, "TXT", "", "*.txt");
    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream in(&file);

    ui->lineName->setText(in.readLine());
    ui->lineDescription->setText(in.readLine());
    ui->lineCoef->setText(in.readLine());
    ui->lineType->setText(in.readLine());

    file.close();
}

void MainWindow::on_btnSaveJson_clicked()
{
    QJsonObject obj;
    obj["name"] = ui->lineName->text();
    obj["description"] = ui->lineDescription->text();
    obj["protectionCoef"] = ui->lineCoef->text().toDouble();
    obj["protectionType"] = ui->lineType->text();

    QFile file("shields.json");

    QJsonArray arr;

    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        if (doc.isArray())
            arr = doc.array();
        file.close();
    }

    arr.append(obj);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return;

    if (arr.isEmpty())
        file.write("");
    else
        file.write(QJsonDocument(arr).toJson());

    file.close();

    QMessageBox::information(this, "OK", "Saved");
}