#include "ThresholdFilter.h"

#include "NegativeFilter.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"


void ThresholdFilter::visit(PGMImage &image) {
    for (size_t i = 0; i < image.getSize(); i++) {
        image.setPixel(i, image.getPixel(i) >= THRESHOLD ? OVER_THRESHOLD : UNDER_THRESHOLD);
    }
}

void ThresholdFilter::visit(PPMImage &image) {
    for (size_t i = 0; i < image.getSize(); i++) {
        unsigned short newRed = image.getRed(i) >= THRESHOLD ? OVER_THRESHOLD : UNDER_THRESHOLD;
        unsigned short newGreen = image.getGreen(i) >= THRESHOLD ? OVER_THRESHOLD : UNDER_THRESHOLD;
        unsigned short newBlue = image.getBlue(i) >= THRESHOLD ? OVER_THRESHOLD : UNDER_THRESHOLD;

        image.setPixel(i, RGB(newRed, newGreen, newBlue));
    }
}

void ThresholdFilter::visit(PBMImage &image) {
    // already threshold
}

String ThresholdFilter::getName() const {
    return "'threshold'";
}

std::unique_ptr<Filter> ThresholdFilter::clone() const {
    return std::make_unique<ThresholdFilter>(*this);
}
