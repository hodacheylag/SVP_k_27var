#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QRect>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private slots:
    void loadImage();
    void calculateIntensity();

private:
    Ui::MainWindow *ui;
    QImage image;
    QRect selectedRect;
    bool selecting;

    void drawRectangle(QPainter &painter);
};

#endif // MAINWINDOW_H
