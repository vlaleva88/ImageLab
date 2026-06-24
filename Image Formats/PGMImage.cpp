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
    is.ignore(1);

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

void PGMImage::save(std::ostream &os) const {
    os << "P5\n";
    os << width << " " << height << "\n";
    os << maxVal << "\n";

    if (maxVal <= 255) {
        for (size_t i = 0; i < pixels.size(); i++) {
            if (pixels[i] > maxVal) {
                throw std::runtime_error("Pixel value exceeds maxVal");
            }

            unsigned char byte = static_cast<unsigned char>(pixels[i]);
            os.write(reinterpret_cast<const char*>(&byte), 1);
        }
    } else {
        for (size_t i = 0; i < pixels.size(); i++) {
            if (pixels[i] > maxVal) {
                throw std::runtime_error("Pixel value exceeds maxVal");
            }

            unsigned char bytes[2] = {
                static_cast<unsigned char>(pixels[i] >> 8),
                static_cast<unsigned char>(pixels[i] & 0xFF)
            };

            os.write(reinterpret_cast<const char*>(bytes), 2);
        }
    }
}

std::unique_ptr<Image> PGMImage::clone() const {
    return std::make_unique<PGMImage>(*this);
}
