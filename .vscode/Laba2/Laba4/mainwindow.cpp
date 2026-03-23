#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTextStream>

void Book::saveToFile()
{
    QFile file("result.txt");

    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "Автор: " << author << "\n";
        out << "Название: " << name << "\n";
        out << "Код: " << code << "\n";
        out << "Наполнение: " << fill << "\n";
        out << "Тип издания: " << type << "\n";
        out << "Жанры: " << genres << "\n";
        out << "-------------------------\n";
        file.close();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->paperRadio->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_resetButton_clicked()
{
    ui->authorEdit->clear();
    ui->nameEdit->clear();
    ui->codeEdit->clear();
    ui->fillEdit->clear();

    ui->paperRadio->setChecked(true);

    ui->detectiveCheck->setChecked(false);
    ui->fantasyCheck->setChecked(false);
    ui->novelCheck->setChecked(false);
}

void MainWindow::on_saveButton_clicked()
{
    QString author = ui->authorEdit->text();
    QString name = ui->nameEdit->text();
    QString code = ui->codeEdit->text();
    QString fill = ui->fillEdit->text();

    QRegularExpression authorRegex("^[А-ЯЁ][а-яё]+ [А-ЯЁ]{1,2}$");
    QRegularExpression nameRegex("^\".+\"$");
    QRegularExpression codeRegex("^\\d{3}-\\d{5}$");
    QRegularExpression fillRegex("^\\d+/\\d+$");

    if (!authorRegex.match(author).hasMatch())
    {
        QMessageBox::warning(this, "Ошибка", "Несоответствие в поле Автор");
        return;
    }

    if (!nameRegex.match(name).hasMatch())
    {
        QMessageBox::warning(this, "Ошибка", "Несоответствие в поле Название");
        return;
    }

    if (!codeRegex.match(code).hasMatch())
    {
        QMessageBox::warning(this, "Ошибка", "Несоответствие в поле Код");
        return;
    }

    if (!fillRegex.match(fill).hasMatch())
    {
        QMessageBox::warning(this, "Ошибка", "Несоответствие в поле Наполнение");
        return;
    }

    QStringList parts = fill.split("/");
    if (parts.size() != 2)
    {
        QMessageBox::warning(this, "Ошибка", "Несоответствие в поле Наполнение");
        return;
    }

    int first = parts[0].toInt();
    int second = parts[1].toInt();

    if (second >= first)
    {
        QMessageBox::warning(this, "Ошибка", "Во втором числе поле Наполнение должно быть меньше первого");
        return;
    }

    QString type;
    if (ui->paperRadio->isChecked())
        type = "Бумажное";
    else
        type = "Электронное";

    QString genres = "";

    if (ui->detectiveCheck->isChecked())
        genres += "Детектив ";

    if (ui->fantasyCheck->isChecked())
        genres += "Фантастика ";

    if (ui->novelCheck->isChecked())
        genres += "Роман ";

    Book book(author, name, code, fill, type, genres.trimmed());
    book.saveToFile();

    QMessageBox::information(this, "Успех", "Данные сохранены в result.txt");
}