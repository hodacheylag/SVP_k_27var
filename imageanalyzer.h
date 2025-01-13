#ifndef IMAGEANALYZER_H
#define IMAGEANALYZER_H

#include <QImage>
#include <QRect>
#include <QVector>

class ImageAnalyzer {
public:
    ImageAnalyzer(const QImage& img, const QRect& rect);

    int calculateMinIntensity();
    int calculateMaxIntensity();
    double calculateAverageIntensity();

private:
    QImage image;
    QRect region;

    QVector<int> extractIntensities();
};

#endif // IMAGEANALYZER_H
