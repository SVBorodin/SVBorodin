#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Book
{
    QString author;
    QString name;
    QString code;
    QString fill;
    QString type;
    QString genres;

    Book(QString a, QString n, QString c,
         QString f, QString t, QString g)
    {
        author = a;
        name = n;
        code = c;
        fill = f;
        type = t;
        genres = g;
    }

    void saveToFile();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_resetButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif