#include "Image.h"

#include <fstream>

void Image::readHeader(std::ifstream &is) {
    std::string header, values, line;
    getline(is, header);
    getline(is, values);
    getline(is, line);
}

Image::Image(const std::string &filename) {
    std::ifstream is(filename, std::ios::binary);
    if (!is.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }
    std::string header;
    std::getline(is, header);

    size_t readWidth, readHeight;
    unsigned short readMaxVal;
    if (!(is >> readWidth >> readHeight >> readMaxVal)) {
        throw std::runtime_error("Invalid file arguments");
    }

    width = readWidth;
    height = readHeight;
    maxVal = readMaxVal;

    is.close();
}
