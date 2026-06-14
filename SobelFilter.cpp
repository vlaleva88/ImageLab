#include "SobelFilter.h"

#include "GreyscaleFilter.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"


void SobelFilter::visit(PPMImage &image) {
    GreyscaleFilter gs;
    image.accept(gs);
    PPMImage result = image;

    for (int y = 1; y < image.getHeight() - 1; y++) {
        for (int x = 1; x < image.getWidth() - 1; x++) {
            int sumX = 0;
            int sumY = 0;

            for (int ky = -1; ky < 2; ky++) {
                for (int kx = -1; kx < 2; kx++) {
                    int index = (y + ky) * image.getWidth() + (kx + x);
                    sumX += image.getRed(index) * KERNEL_GX[ky + 1][kx + 1];
                    sumY += image.getRed(index) * KERNEL_GY[ky + 1][kx + 1];
                }
            }
            int value = static_cast<int>(std::sqrt(sumX * sumX + sumY * sumY));
            value = std::clamp(value, 0, 255);

            result.setPixel(y * image.getWidth() + x, RGB(value, value, value));
        }
    }
    image = result;
}

void SobelFilter::visit(PGMImage &image) {
    PGMImage result = image;

    for (int y = 1; y < image.getHeight() - 1; y++) {
        for (int x = 1; x < image.getWidth() - 1; x++) {
            int sumX = 0;
            int sumY = 0;

            for (int ky = -1; ky < 2; ky++) {
                for (int kx = -1; kx < 2; kx++) {
                    int index = (y + ky) * image.getWidth() + (kx + x);
                    sumX += image.getPixel(index) * KERNEL_GX[ky + 1][kx + 1];
                    sumY += image.getPixel(index) * KERNEL_GY[ky + 1][kx + 1];
                }
            }
            int value = static_cast<int>(std::sqrt(sumX * sumX + sumY * sumY));
            value = std::clamp(value, 0, 255);

            result.setPixel(y * image.getWidth() + x, value);
        }
    }
    image = result;
}

void SobelFilter::visit(PBMImage &image) {
    PBMImage result = image;

    for (int y = 1; y < image.getHeight() - 1; y++) {
        for (int x = 1; x < image.getWidth() - 1; x++) {
            constexpr int THRESHOLD = 128;
            int sumX = 0;
            int sumY = 0;

            for (int ky = -1; ky < 2; ky++) {
                for (int kx = -1; kx < 2; kx++) {
                    int index = (y + ky) * image.getWidth() + (kx + x);
                    int pixel = image.getPixel(index) ? 255 : 0;
                    sumX += pixel * KERNEL_GX[ky + 1][kx + 1];
                    sumY += pixel * KERNEL_GY[ky + 1][kx + 1];
                }
            }
            bool value = std::sqrt(sumX * sumX + sumY * sumY) >= THRESHOLD;

            result.setPixel(y * image.getWidth() + x, value);
        }
    }
    image = result;
}

String SobelFilter::getName() const {
    return "'sobel'";
}

std::unique_ptr<Filter> SobelFilter::clone() const {
    return std::make_unique<SobelFilter>(*this);
}