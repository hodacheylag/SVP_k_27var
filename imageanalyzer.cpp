#include "imageanalyzer.h"
#include <algorithm>
#include <numeric>
#include <QMessageBox>

ImageAnalyzer::ImageAnalyzer(const QImage& img, const QRect& rect)
    : image(img), region(rect) {}

QVector<int> ImageAnalyzer::extractIntensities() {
    QVector<int> intensities;
    for (int y = region.top(); y <= region.bottom(); ++y) {
        for (int x = region.left(); x <= region.right(); ++x) {
            if (x >= 0 && x < image.width() && y >= 0 && y < image.height()) {
                intensities.append(qGray(image.pixel(x, y)));    
            }
        }
    }

    if (intensities.empty()) {
        intensities.append(0);
    }

    return intensities;
}

int ImageAnalyzer::calculateMinIntensity() {
    QVector<int> intensities = extractIntensities();
    return *std::min_element(intensities.begin(), intensities.end());
}

int ImageAnalyzer::calculateMaxIntensity() {
    QVector<int> intensities = extractIntensities();
    return *std::max_element(intensities.begin(), intensities.end());
}

double ImageAnalyzer::calculateAverageIntensity() {
    QVector<int> intensities = extractIntensities();
    return std::accumulate(intensities.begin(), intensities.end(), 0.0) / intensities.size();
}
