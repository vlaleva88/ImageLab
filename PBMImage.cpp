#include "PBMImage.h"

PBMImage::PBMImage(size_t width, size_t height) : Image(width, height) {
    pixels.resize(width * height);
}

size_t PBMImage::getWidth() const {
    return width;
}

size_t PBMImage::getHeight() const {
    return height;
}

size_t PBMImage::getSize() const {
    return width * height;
}

std::unique_ptr<Image> PBMImage::clone() const {
    return std::make_unique<PBMImage>(*this);
}
