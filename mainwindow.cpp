#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);

    Level level(":/levels/level1.json");
    ((SceneWidget *)centralWidget())->setLevel(level);
}

MainWindow::~MainWindow() {
}

