#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct RemotePlayer {
    int id;
    QString color;
    int x;
    int y;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_connectButton_clicked();
    void on_upButton_clicked();
    void on_downButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_imitationButton_clicked();
    void on_musicToggle_clicked();
    void sendDataRequest();
    void processSimulation();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QTimer *updateTimer;
    QTimer *simTimer;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    int myId;
    QString myColor;
    int myX;
    int myY;

    QString weather;
    QMap<int, RemotePlayer> remotePlayers;
    bool isImitation;
};
#endif // MAINWINDOW_H