#include "PBMImage.h"

#include <fstream>

PBMImage::PBMImage(const String& filename) : Image(filename) {
    std::ifstream is(filename.c_str(), std::ios::binary);
    if (!is.is_open()) {
        throw std::runtime_error(("Could not open file " + filename).c_str());
    }
    readHeader(is);

    // ?
    size_t rowBytes = (width + 7) / 8;
    Vector<unsigned char> buffer(rowBytes * height);

    is.read(reinterpret_cast<char*>(buffer.getData()), buffer.size());


    if (!is) {
        throw std::runtime_error(("Could not read file " + filename).c_str());
    }
    pixels.resize(width * height);
    //?
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            unsigned char byte = buffer[y * rowBytes + x / 8];

            pixels.set((y * width + x),(byte >> (7 - (x % 8))) & 1);
        }
    }
    is.close();
}

void PBMImage::accept(ImageVisitor &visitor) {
    visitor.visit(*this);
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

bool PBMImage::getPixel(size_t index) const {
    return pixels.get(index);
}

void PBMImage::setPixel(size_t index, bool value) {
    pixels.set(index, value);
}

void PBMImage::save(std::ostream &os) const {
    os << "P4\n";
    os << width << " " << height << "\n";

    for (size_t row = 0; row < height; ++row)
    {
        unsigned char byte = 0;
        int bitCount = 0;

        for (size_t col = 0; col < width; ++col)
        {
            bool pixel = getPixel(row * width + col);
            byte <<= 1;
            if (pixel) {
                byte |= 1;
            }
            ++bitCount;

            if (bitCount == 8)
            {
                os.write(reinterpret_cast<const char*>(&byte), 1);
                byte = 0;
                bitCount = 0;
            }
        }
        if (bitCount > 0)
        {
            byte <<= (8 - bitCount);
            os.write(reinterpret_cast<const char*>(&byte), 1);
        }
    }
}

std::unique_ptr<Image> PBMImage::clone() const {
    return std::make_unique<PBMImage>(*this);
}
