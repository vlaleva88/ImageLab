#include "../filters/BlurFilter.h"

#include "../Image Formats/PBMImage.h"
#include "../Image Formats/PGMImage.h"
#include "../Image Formats/PPMImage.h"

void BlurFilter::visit(PBMImage &image) {
    PBMImage result = image;

    for (int y = 0; y < image.getHeight(); y++) {
        for (int x = 0; x < image.getWidth(); x++) {

            int count = 0;
            int sum = 0;

            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int newX = x + dx;
                    int newY = y + dy;

                    if (newX >= 0 && newY >= 0 &&
                        newX < image.getWidth() && newY < image.getHeight()) {
                        int index = newX + newY * image.getWidth();
                        sum += image.getPixel(index);
                        count++;
                    }
                }
            }
            result.setPixel(y * image.getWidth() + x, sum / count);
        }
    }
    image = result;
}

void BlurFilter::visit(PGMImage &image) {
    PGMImage result = image;

    for (int y = 0; y < image.getHeight(); y++) {
        for (int x = 0; x < image.getWidth(); x++) {

            int count = 0;
            int sum = 0;

            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int newX = x + dx;
                    int newY = y + dy;

                    if (newX >= 0 && newY >= 0 &&
                        newX < image.getWidth() && newY < image.getHeight()) {
                        int index = newX + newY * image.getWidth();
                        sum += image.getPixel(index);
                        count++;
                        }
                }
            }
            result.setPixel(y * image.getWidth() + x, sum / count);
        }
    }
    image = result;
}

void BlurFilter::visit(PPMImage &image) {
    PPMImage result = image;

    // std::cout << &result.getPixels() << std::endl;
    // std::cout << &image.getPixels();

    for (int y = 0; y < image.getHeight(); y++) {
        for (int x = 0; x < image.getWidth(); x++) {

            int count = 0;
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int newX = x + dx;
                    int newY = y + dy;

                    if (newX >= 0 && newY >= 0 &&
                        newX < image.getWidth() && newY < image.getHeight()) {
                        int index = newX + newY * image.getWidth();
                        sumRed += image.getRed(index);
                        sumGreen += image.getGreen(index);
                        sumBlue += image.getBlue(index);
                        count++;
                        }
                }
            }
            RGB newPixel(sumRed/count, sumGreen/count, sumBlue/count);
            result.setPixel(y * image.getWidth() + x, newPixel);
        }
    }
    image = result;
}

String BlurFilter::getName() const {
    return "'blur'";
}

std::unique_ptr<Filter> BlurFilter::clone() const {
    return std::make_unique<BlurFilter>(*this);
}
