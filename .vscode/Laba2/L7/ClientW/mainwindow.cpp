#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPainter>
#include <QRandomGenerator>
#include <QUrl>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , myX(0), myY(0), isImitation(false), weather("Ясно")
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    updateTimer = new QTimer(this);
    simTimer = new QTimer(this);

    ui->colorComboBox->addItem("Синий", "#0000FF");
    ui->colorComboBox->addItem("Красный", "#FF0000");
    ui->colorComboBox->addItem("Зеленый", "#00FF00");
    ui->colorComboBox->addItem("Желтый", "#FFFF00");
    myColor = "#0000FF";

    ui->upButton->setText("↑");
    ui->downButton->setText("↓");
    ui->leftButton->setText("←");
    ui->rightButton->setText("→");

    connect(ui->colorComboBox, &QComboBox::currentIndexChanged, [=](int index){
        myColor = ui->colorComboBox->itemData(index).toString();
        sendDataRequest();
    });

    connect(updateTimer, &QTimer::timeout, this, &MainWindow::sendDataRequest);
    connect(simTimer, &QTimer::timeout, this, &MainWindow::processSimulation);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("C:/Users/1/Documents/ClientW/GCmusic.wav"));
    player->setLoops(QMediaPlayer::Infinite);
    audioOutput->setVolume(50);

    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    bool ok;
    int id = ui->idEdit->text().toInt(&ok);
    if (!ok || id < 0 || id > 1000) {
        QMessageBox::critical(this, "Ошибка", "ID должен быть числом от 0 до 1000!");
        return;
    }

    myId = id;
    socket->connectToHost(ui->addressEdit->text(), ui->portEdit->text().toUShort());

    if (socket->waitForConnected(2000)) {
        QString request = QString("LOGIN %1").arg(myId);
        socket->write(request.toUtf8());

        if (socket->waitForReadyRead(1000)) {
            QByteArray data = socket->readAll();
            QString response = QString::fromUtf8(data);
            QStringList mainParts = response.split('|');
            if (mainParts.size() >= 2) {
                QStringList subParts = mainParts[1].split(';');
                QStringList myData = subParts[0].split(',');
                if (myData.size() == 3) {
                    myColor = myData[0];
                    myX = myData[1].toInt();
                    myY = myData[2].toInt();

                    int colorIndex = ui->colorComboBox->findData(myColor);
                    if (colorIndex != -1) {
                        ui->colorComboBox->blockSignals(true);
                        ui->colorComboBox->setCurrentIndex(colorIndex);
                        ui->colorComboBox->blockSignals(false);
                    }
                }
            }
        }
        socket->disconnectFromHost();

        ui->stackedWidget->setCurrentIndex(1);
        updateTimer->start(300);
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось подключиться к serverу!");
    }
}

void MainWindow::sendDataRequest()
{
    if (socket->state() != QAbstractSocket::ConnectedState) {
        socket->connectToHost(ui->addressEdit->text(), ui->portEdit->text().toUShort());
        if (!socket->waitForConnected(500)) return;
    }

    QString request = QString("UPDATE %1 %2 %3 %4").arg(myId).arg(myColor).arg(myX).arg(myY);
    socket->write(request.toUtf8());

    if (socket->waitForReadyRead(1000)) {
        QByteArray data = socket->readAll();
        QString response = QString::fromUtf8(data);

        QStringList mainParts = response.split('|');
        if (mainParts.size() >= 2) {
            QString rawWeather = mainParts[0];
            if (rawWeather == "Clear") weather = "Ясно";
            else if (rawWeather == "Cloudy") weather = "Пасмурно";
            else if (rawWeather == "Rainy") weather = "Дождливо";
            else weather = rawWeather;

            ui->weatherLabel->setText("Погода:\n" + weather);

            QStringList subParts = mainParts[1].split(';');
            remotePlayers.clear();
            for (int i = 1; i < subParts.size(); ++i) {
                QStringList pData = subParts[i].split(',');
                if (pData.size() == 4) {
                    RemotePlayer rp;
                    rp.id = pData[0].toInt();
                    rp.color = pData[1];
                    rp.x = pData[2].toInt();
                    rp.y = pData[3].toInt();
                    remotePlayers[rp.id] = rp;
                }
            }
        }
    }
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    if (ui->stackedWidget->currentIndex() != 1) return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect canvasRect(20, 20, 400, 400);
    painter.setPen(QPen(Qt::black, 2));
    painter.setBrush(Qt::white);
    painter.drawRect(canvasRect);

    painter.setPen(QPen(Qt::lightGray, 1, Qt::DashLine));
    for(int i = 1; i < 20; ++i) {
        painter.drawLine(20 + i*20, 20, 20 + i*20, 420);
        painter.drawLine(20, 20 + i*20, 420, 20 + i*20);
    }

    auto toScreen = [](int worldX, int worldY) -> QPoint {
        int screenX = 20 + (worldX + 10) * 20;
        int screenY = 20 + (10 - worldY) * 20;
        return QPoint(screenX, screenY);
    };

    for (const RemotePlayer &rp : remotePlayers.values()) {
        QPoint p = toScreen(rp.x, rp.y);
        painter.setBrush(QColor(rp.color));
        painter.setPen(Qt::black);
        painter.drawRect(p.x() - 8, p.y() - 8, 16, 16);
    }

    QPoint myPoint = toScreen(myX, myY);
    painter.setBrush(QColor(myColor));
    painter.setPen(QPen(Qt::black, 2));
    painter.drawEllipse(myPoint.x() - 9, myPoint.y() - 9, 18, 18);
}

void MainWindow::on_upButton_clicked()    { if (myY < 10)  { myY++; sendDataRequest(); } }
void MainWindow::on_downButton_clicked()  { if (myY > -10) { myY--; sendDataRequest(); } }
void MainWindow::on_leftButton_clicked()  { if (myX > -10) { myX--; sendDataRequest(); } }
void MainWindow::on_rightButton_clicked() { if (myX < 10)  { myX++; sendDataRequest(); } }

void MainWindow::on_imitationButton_clicked()
{
    isImitation = !isImitation;
    if (isImitation) {
        ui->upButton->setEnabled(false);
        ui->downButton->setEnabled(false);
        ui->leftButton->setEnabled(false);
        ui->rightButton->setEnabled(false);
        simTimer->start(1000);
    } else {
        ui->upButton->setEnabled(true);
        ui->downButton->setEnabled(true);
        ui->leftButton->setEnabled(true);
        ui->rightButton->setEnabled(true);
        simTimer->stop();
    }
}

void MainWindow::processSimulation()
{
    int dir = QRandomGenerator::global()->bounded(4);
    if (dir == 0 && myY < 10)  myY++;
    else if (dir == 1 && myY > -10) myY--;
    else if (dir == 2 && myX > -10) myX--;
    else if (dir == 3 && myX < 10)  myX++;

    sendDataRequest();
}

void MainWindow::on_musicToggle_clicked()
{
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->pause();
        ui->musicToggle->setText("Включить музыку");
    } else {
        player->play();
        ui->musicToggle->setText("Выключить музыку");
    }
}