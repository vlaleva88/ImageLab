#include "SharpenFilter.h"

#include "PGMImage.h"
#include "PPMImage.h"

void SharpenFilter::visit(PGMImage &image) {
    PGMImage result = image;
    for (int y = 1; y < image.getHeight() - 1; y++) {
        for (int x = 1; x < image.getWidth() - 1; x++) {
            int sum = 0;

            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int index = (y + ky) * image.getWidth() + (kx + x);
                    int weight = KERNEL[ky + 1][kx + 1];
                    sum += image.getPixel(index) * weight;
                }
            }
            sum = std::clamp(sum, 0, 255);
            result.setPixel(y * image.getWidth() + x, sum);
        }
    }
    image = result;
}

void SharpenFilter::visit(PPMImage &image) {
    PPMImage result = image;
    for (int y = 1; y < image.getHeight() - 1; y++) {
        for (int x = 1; x < image.getWidth() - 1; x++) {
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;

            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int index = (y + ky) * image.getWidth() + (kx + x);
                    int weight = KERNEL[ky + 1][kx + 1];
                    redSum += image.getRed(index) * weight;
                    greenSum += image.getGreen(index) * weight;
                    blueSum += image.getBlue(index) * weight;
                }
            }
            redSum = std::clamp(redSum, 0, 255);
            greenSum = std::clamp(greenSum, 0, 255);
            blueSum = std::clamp(blueSum, 0, 255);

            result.setPixel(y * image.getWidth() + x, RGB(redSum, greenSum, blueSum));
        }
    }
    image = result;
}

void SharpenFilter::visit(PBMImage &image) {
    // without change
}

String SharpenFilter::getName() const {
    return "'sharpen'";
}

std::unique_ptr<Filter> SharpenFilter::clone() const {
    return std::make_unique<SharpenFilter>(*this);
}