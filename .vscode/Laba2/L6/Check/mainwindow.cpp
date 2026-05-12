#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include <QTableWidgetItem>

#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableCorrect->setColumnCount(4);
    ui->tableBroken->setColumnCount(4);

    QStringList headers;

    headers << "Название"
            << "Описание"
            << "Коэффициент"
            << "Тип защиты";

    ui->tableCorrect->setHorizontalHeaderLabels(headers);
    ui->tableBroken->setHorizontalHeaderLabels(headers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isValidObject(QJsonObject obj)
{
    if(obj["name"].toString().isEmpty())
        return false;

    if(obj["description"].toString().isEmpty())
        return false;

    if(obj["protectionType"].toString().isEmpty())
        return false;

    if(obj["protectionCoef"].toDouble() <= 0)
        return false;

    return true;
}

void MainWindow::on_btnOpen_clicked()
{
    ui->tableCorrect->setRowCount(0);
    ui->tableBroken->setRowCount(0);

    brokenArray = QJsonArray();

    QString path = QFileDialog::getOpenFileName(
        this,
        "Открыть JSON",
        "",
        "JSON (*.json)"
        );

    if(path.isEmpty())
        return;

    QFile file(path);

    if(!file.open(QIODevice::ReadOnly))
        return;

    QByteArray data = file.readAll();

    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);

    if(!doc.isArray())
        return;

    QJsonArray array = doc.array();

    QList<QJsonObject> validList;

    for(QJsonValue value : array)
    {
        QJsonObject obj = value.toObject();

        if(isValidObject(obj))
        {
            validList.append(obj);
        }
        else
        {
            brokenArray.append(obj);

            int row = ui->tableBroken->rowCount();

            ui->tableBroken->insertRow(row);

            ui->tableBroken->setItem(
                row,
                0,
                new QTableWidgetItem(obj["name"].toString())
                );

            ui->tableBroken->setItem(
                row,
                1,
                new QTableWidgetItem(obj["description"].toString())
                );

            ui->tableBroken->setItem(
                row,
                2,
                new QTableWidgetItem(
                    QString::number(
                        obj["protectionCoef"].toDouble()
                        )
                    )
                );

            ui->tableBroken->setItem(
                row,
                3,
                new QTableWidgetItem(
                    obj["protectionType"].toString()
                    )
                );
        }
    }

    std::sort(
        validList.begin(),
        validList.end(),
        [](QJsonObject a, QJsonObject b)
        {
            return a["name"].toString() >
                   b["name"].toString();
        }
        );

    for(QJsonObject obj : validList)
    {
        int row = ui->tableCorrect->rowCount();

        ui->tableCorrect->insertRow(row);

        ui->tableCorrect->setItem(
            row,
            0,
            new QTableWidgetItem(obj["name"].toString())
            );

        ui->tableCorrect->setItem(
            row,
            1,
            new QTableWidgetItem(obj["description"].toString())
            );

        ui->tableCorrect->setItem(
            row,
            2,
            new QTableWidgetItem(
                QString::number(
                    obj["protectionCoef"].toDouble()
                    )
                )
            );

        ui->tableCorrect->setItem(
            row,
            3,
            new QTableWidgetItem(
                obj["protectionType"].toString()
                )
            );
    }

    QFile brokenFile("broken.json");

    if(brokenFile.open(QIODevice::WriteOnly))
    {
        QJsonDocument brokenDoc(brokenArray);

        brokenFile.write(brokenDoc.toJson());

        brokenFile.close();
    }
}