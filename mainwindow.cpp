#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageanalyzer.h"

#include <QFileDialog>
#include <QPainter>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), selecting(false) {
    ui->setupUi(this);

    connect(ui->actionLoadImage, &QAction::triggered, this, &MainWindow::loadImage);
    connect(ui->actionAnalyze, &QAction::triggered, this, &MainWindow::calculateIntensity);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadImage() {
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть изображение", "", "Изображения (*.png *.jpg *.bmp)");
    if (!fileName.isEmpty()) {
        if (!image.load(fileName)) {
            QMessageBox::warning(this, "Ошибка", "Не удалось загрузить изображение.");
            return;
        }
        selectedRect = QRect();
        update();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (!image.isNull() && event->button() == Qt::LeftButton) {
        selecting = true;
        selectedRect.setTopLeft(event->pos());
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (selecting && event->button() == Qt::LeftButton) {
        selecting = false;
        selectedRect.setBottomRight(event->pos());
        selectedRect = selectedRect.normalized();
        update();
    }
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (!image.isNull()) {
        painter.drawImage(0, 0, image);
    }
    if (!selectedRect.isNull()) {
        painter.setPen(Qt::red);
        painter.drawRect(selectedRect);
    }
}

void MainWindow::calculateIntensity() {
    if (image.isNull() || selectedRect.isNull()) {
        QMessageBox::warning(this, "Ошибка", "Выберите изображение и выделите область для анализа.");
        return;
    }

    ImageAnalyzer analyzer(image, selectedRect);

    int minIntensity = analyzer.calculateMinIntensity();
    int maxIntensity = analyzer.calculateMaxIntensity();
    double avgIntensity = analyzer.calculateAverageIntensity();

    QMessageBox::information(this, "Результаты анализа",
                             QString("Минимальная интенсивность: %1\nМаксимальная интенсивность: %2\nСредняя интенсивность: %3")
                                 .arg(minIntensity)
                                 .arg(maxIntensity)
                                 .arg(avgIntensity, 0, 'f', 2));
}
