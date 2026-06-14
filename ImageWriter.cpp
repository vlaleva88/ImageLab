#include "ImageWriter.h"

#include <fstream>

void ImageWriter::write(const Image &image, const String &filename) {
    std::ofstream os(filename.c_str());
    image.save(os);
}
