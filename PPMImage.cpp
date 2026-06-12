#include "PPMImage.h"

#include <fstream>

PPMImage::PPMImage(const std::string &filename) : Image(filename) {
    std::ifstream is(filename, std::ios::binary);
    if (!is.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }
    readHeader(is);

    const size_t size = width * height;
    pixels.reserve(size);
    for (size_t i = 0; i < size; i++) {
        unsigned char r, g, b;
        is.read(reinterpret_cast<char*>(&r), 1);
        is.read(reinterpret_cast<char*>(&g), 1);
        is.read(reinterpret_cast<char*>(&b), 1);
        // pixels[i] = RGB(r,g,b);
        pixels.emplace_back(r, g, b);
    }
}

size_t PPMImage::getWidth() const {
    return width;
}

size_t PPMImage::getHeight() const {
    return height;
}

size_t PPMImage::getSize() const {
    return width * height;
}

std::unique_ptr<Image> PPMImage::clone() const {
    return std::make_unique<PPMImage>(*this);
}