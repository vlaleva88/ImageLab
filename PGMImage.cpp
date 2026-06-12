#include "PGMImage.h"

#include <fstream>

PGMImage::PGMImage(const std::string &filename) : Image(filename) {
    std::ifstream is(filename, std::ios::binary);
    if (!is.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }
    readHeader(is);

    pixels.resize(width * height);
    is.read(reinterpret_cast<char*>(pixels.data()),
        pixels.size());

    if (!is) {
        throw std::runtime_error("Could not read file " + filename);
    }

    is.close();
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
    return std::make_unique<PGMImage>(*this);
}
