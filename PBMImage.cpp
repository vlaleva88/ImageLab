#include "PBMImage.h"

#include <fstream>

PBMImage::PBMImage(const std::string& filename) : Image(filename) {
    std::ifstream is(filename, std::ios::binary);
    if (!is.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }
    readHeader(is);

    pixels.resize(width * height);
    is.read(,
        pixels.size());

    if (!is) {
        throw std::runtime_error("Could not read file " + filename);
    }

    is.close();
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