#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);

    Level level(":/levels/level1.json");
    sceneWidget->setLevel(level);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    timer->setInterval(20);
}

MainWindow::~MainWindow() {
    delete timer;
}

void MainWindow::on_pbStart_clicked() {
    timer->start();
}

void MainWindow::on_pbStop_clicked() {
    timer->stop();
    sceneWidget->reset();
}

void MainWindow::timer_timeout() {
    sceneWidget->incX();
}
