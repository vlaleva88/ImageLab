#include "GreyscaleFilter.h"

#include "PPMImage.h"
#include "Vector.hpp"

void GreyscaleFilter::visit(PPMImage &image) {
    Vector<RGB> pixels = image.getPixels();
    for (size_t i = 0; i < image.getSize(); i++) {
        unsigned char grey = 0.299 * image.getRed(i) + 0.587 * image.getGreen(i) +
            0.114 * image.getBlue(i);

        pixels[i].red = grey;
        pixels[i].green = grey;
        pixels[i].blue = grey;
    }
}

void GreyscaleFilter::visit(PBMImage &image) {
    // unchange
}

void GreyscaleFilter::visit(PGMImage &image) {
    // already greyscale
}

String GreyscaleFilter::getName() const {
    return "'greyscale'";
}

std::unique_ptr<Filter> GreyscaleFilter::clone() const {
    return std::make_unique<GreyscaleFilter>(*this);
}
