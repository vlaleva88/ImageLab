#include "PGMImage.h"

#include <fstream>

PGMImage::PGMImage(const String &filename) : Image(filename) {
    std::ifstream is(filename.c_str(), std::ios::binary);
    if (!is.is_open()) {
        throw std::runtime_error(("Could not open file " + filename).c_str());
    }
    readHeader(is);
    unsigned short readMaxVal;
    is >> readMaxVal;
    maxVal = readMaxVal;

    pixels.resize(width * height);
    is.read(reinterpret_cast<char*>(pixels.getData()),
        pixels.size());

    if (!is) {
        throw std::runtime_error(("Could not read file " + filename).c_str());
    }

    is.close();
}

void PGMImage::accept(ImageVisitor &visitor) {
    visitor.visit(*this);
}

Vector<unsigned short> & PGMImage::getPixels() {
    return pixels;
}

unsigned short PGMImage::getPixel(size_t index) const {
    return pixels[index];
}

void PGMImage::setPixel(size_t index, unsigned short value) {
    pixels[index] = value;
}

size_t PGMImage::getWidth() const {
    return width;
}

size_t PGMImage::getHeight() const {
    return height;
}

size_t PGMImage::getSize() const {
    return width * height;
}

unsigned short PGMImage::getMaxVal() const {
    return maxVal;
}

std::unique_ptr<Image> PGMImage::clone() const {
    return std::make_unique<PGMImage>(*this);
}
