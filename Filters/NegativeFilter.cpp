#include "../Filters/NegativeFilter.h"

#include "../Image Formats/PBMImage.h"
#include "../Image Formats/PGMImage.h"
#include "../Image Formats/PPMImage.h"

void NegativeFilter::visit(PPMImage &image) {
    Vector<RGB>& pixels = image.getPixels();
    for (size_t i = 0; i < image.getSize(); i++) {
        pixels[i].red = image.getMaxVal() - pixels[i].red;
        pixels[i].green = image.getMaxVal() - pixels[i].green;
        pixels[i].blue = image.getMaxVal() - pixels[i].blue;
    }
}

void NegativeFilter::visit(PBMImage &image) {
    for (size_t i = 0; i < image.getSize(); i++) {
        image.setPixel(i, !image.getPixel(i));
    }
}

void NegativeFilter::visit(PGMImage &image) {
    Vector<unsigned short>& pixels = image.getPixels();
    for (size_t i = 0; i < image.getSize(); i++) {
        pixels[i] = image.getMaxVal() - pixels[i];
    }
}

String NegativeFilter::getName() const {
    return "'negative'";
}

std::unique_ptr<Filter> NegativeFilter::clone() const {
    return std::make_unique<NegativeFilter>(*this);
}
