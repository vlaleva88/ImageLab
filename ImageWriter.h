#ifndef IMAGELAB_IMAGEWRITER_H
#define IMAGELAB_IMAGEWRITER_H
#include "Image.h"


class ImageWriter {
public:
    static void write(const Image& image, const String& filename);
};


#endif //IMAGELAB_IMAGEWRITER_H