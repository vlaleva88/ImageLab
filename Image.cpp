#include "Image.h"

#include <fstream>

void Image::readHeader(std::ifstream &is) {
    String header, values, line;
    getline(is, header);
    getline(is, values);
    // getline(is, line);
}

Image::Image(const String &filename) {
    std::ifstream is(filename.c_str(), std::ios::binary);
    if (!is.is_open()) {
        throw std::runtime_error(("Could not open file " + filename).c_str());
    }
    String header;
    getline(is, header);

    size_t readWidth, readHeight;
    if (!(is >> readWidth >> readHeight)) {
        throw std::runtime_error("Invalid file arguments");
    }

    width = readWidth;
    height = readHeight;

    is.close();
}
