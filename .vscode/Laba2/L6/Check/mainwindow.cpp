#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTableWidgetItem>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableCorrect->setColumnCount(4);
    ui->tableBroken->setColumnCount(4);

    QStringList headers;
    headers << "Название" << "Описание" << "Коэфф" << "Тип";

    ui->tableCorrect->setHorizontalHeaderLabels(headers);
    ui->tableBroken->setHorizontalHeaderLabels(headers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isValid(const QJsonObject &obj)
{
    if (obj.value("name").toString().trimmed().isEmpty())
        return false;

    if (obj.value("protectionCoef").toDouble(0) <= 0)
        return false;

    if (obj.value("protectionType").toString().trimmed().isEmpty())
        return false;

    return true;
}

void MainWindow::on_btnOpen_clicked()
{
    ui->tableCorrect->setRowCount(0);
    ui->tableBroken->setRowCount(0);

    QJsonArray correct;
    QJsonArray broken;

    QString path = QFileDialog::getOpenFileName(this, "Open JSON", "", "*.json");
    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) return;

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) return;

    QJsonArray arr = doc.array();

    for (const QJsonValue &val : arr)
    {
        QJsonObject obj = val.toObject();

        if (isValid(obj))
            correct.append(obj);
        else
            broken.append(obj);
    }

    for (int i = 0; i < correct.size(); i++)
    {
        for (int j = i + 1; j < correct.size(); j++)
        {
            QString a = correct[i].toObject().value("name").toString();
            QString b = correct[j].toObject().value("name").toString();

            if (a > b)
            {
                QJsonValue tmp = correct[i];
                correct[i] = correct[j];
                correct[j] = tmp;
            }
        }
    }

    for (const QJsonValue &val : correct)
    {
        QJsonObject o = val.toObject();

        int r = ui->tableCorrect->rowCount();
        ui->tableCorrect->insertRow(r);

        ui->tableCorrect->setItem(r, 0, new QTableWidgetItem(o.value("name").toString()));
        ui->tableCorrect->setItem(r, 1, new QTableWidgetItem(o.value("description").toString()));
        ui->tableCorrect->setItem(r, 2, new QTableWidgetItem(QString::number(o.value("protectionCoef").toDouble())));
        ui->tableCorrect->setItem(r, 3, new QTableWidgetItem(o.value("protectionType").toString()));
    }

    for (const QJsonValue &val : broken)
    {
        QJsonObject o = val.toObject();

        int r = ui->tableBroken->rowCount();
        ui->tableBroken->insertRow(r);

        QString name = o.value("name").toString();
        QTableWidgetItem *nameItem = new QTableWidgetItem(name);
        if (name.trimmed().isEmpty())
            nameItem->setBackground(Qt::red);
        ui->tableBroken->setItem(r, 0, nameItem);

        ui->tableBroken->setItem(r, 1, new QTableWidgetItem(o.value("description").toString()));

        double coef = o.value("protectionCoef").toDouble(0);
        QTableWidgetItem *coefItem = new QTableWidgetItem(QString::number(coef));
        if (coef <= 0)
            coefItem->setBackground(Qt::red);
        ui->tableBroken->setItem(r, 2, coefItem);

        QString type = o.value("protectionType").toString();
        QTableWidgetItem *typeItem = new QTableWidgetItem(type);
        if (type.trimmed().isEmpty())
            typeItem->setBackground(Qt::red);
        ui->tableBroken->setItem(r, 3, typeItem);
    }

    QFile cFile("correct.json");
    if (correct.isEmpty())
    {
        if (cFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
            cFile.close();
    }
    else
    {
        if (cFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            cFile.write(QJsonDocument(correct).toJson());
            cFile.close();
        }
    }

    QFile bFile("broken.json");
    if (broken.isEmpty())
    {
        if (bFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
            bFile.close();
    }
    else
    {
        if (bFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            bFile.write(QJsonDocument(broken).toJson());
            bFile.close();
        }
    }
}