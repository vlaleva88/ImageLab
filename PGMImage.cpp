#include "PGMImage.h"

PGMImage::PGMImage(size_t width, size_t height) : Image(width, height) {
    type = ImageType::PGM;
}

size_t PGMImage::getWidth() const {
    return width;
}

size_t PGMImage::getHeight() const {
    return height;
}

size_t PGMImage::getSize() const {
    return width * height; // ???
}

std::unique_ptr<Image> PGMImage::clone() const {
    return std::make_unique<PGMImage>(width, height);
}
