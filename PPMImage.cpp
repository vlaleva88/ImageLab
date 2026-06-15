#include "PPMImage.h"

#include <fstream>

PPMImage::PPMImage(const String &filename) : Image(filename) {
    std::ifstream is(filename.c_str(), std::ios::binary);
    if (!is.is_open()) {
        throw std::runtime_error(("Could not open file " + filename).c_str());
    }
    readHeader(is);
    unsigned short readMaxVal;
    is >> readMaxVal;
    maxVal = readMaxVal;

    const size_t size = width * height;
    pixels.reserve(size);
    for (size_t i = 0; i < size; i++) {
        unsigned char r, g, b;
        is.read(reinterpret_cast<char*>(&r), 1);
        is.read(reinterpret_cast<char*>(&g), 1);
        is.read(reinterpret_cast<char*>(&b), 1);
        pixels.pushBack(RGB(r, g, b));
    }
    is.close();
}

void PPMImage::accept(ImageVisitor &visitor) {
    visitor.visit(*this);
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

unsigned short PPMImage::getMaxVal() const {
    return maxVal;
}

Vector<RGB>& PPMImage::getPixels() {
    return pixels;
}

RGB PPMImage::getPixel(size_t index) const {
    return pixels[index];
}

void PPMImage::setPixel(size_t index, const RGB &value) {
    pixels[index] = value;
}

unsigned char PPMImage::getRed(size_t index) {
    return pixels[index].red;
}

unsigned char PPMImage::getGreen(size_t index) {
    return pixels[index].green;
}

unsigned char PPMImage::getBlue(size_t index) {
    return pixels[index].blue;
}

void PPMImage::save(std::ostream &os) const {
    os << "P6\n";
    os << width << " " << height << "\n";
    os << maxVal << "\n";

    for (size_t i = 0; i < pixels.size(); i++) {
        os.write(reinterpret_cast<const char*>(&pixels[i].red), 1);
        os.write(reinterpret_cast<const char*>(&pixels[i].green), 1);
        os.write(reinterpret_cast<const char*>(&pixels[i].blue), 1);
    }
}

std::unique_ptr<Image> PPMImage::clone() const {
    return std::make_unique<PPMImage>(*this);
}