#include "PPMImage.h"

#include <fstream>

PPMImage::PPMImage(size_t width, size_t height) : Image(width, height) {
    maxVal = MAX_VAL_PPM;
}

size_t PPMImage::getWidth() const {
    return width;
}

size_t PPMImage::getHeight() const {
    return height;
}

size_t PPMImage::getSize() const {
    return width * height * 3;
}

std::unique_ptr<Image> PPMImage::clone() const {
    return std::make_unique<PPMImage>(*this);
}

// void PPMImage::readPixels(const std::string &filename) {
//     std::ifstream is(filename, std::ios::binary);
//     if (!is.is_open()) {
//         throw std::runtime_error("Could not open file " + filename);
//     }
//
//     const size_t size = getSize();
//     for (size_t i = 0; i < size; i++) {
//         unsigned char r, g, b;
//         is.read(reinterpret_cast<char*>(&r), 1);
//         is.read(reinterpret_cast<char*>(&g), 1);
//         is.read(reinterpret_cast<char*>(&b), 1);
//         // bytes[i] = RGB(r,g,b);
//         pixels.emplace_back(r, g, b); // !!!
//     }
// }
