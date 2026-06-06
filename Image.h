#ifndef IMAGELAB_IMAGE_H
#define IMAGELAB_IMAGE_H

#include<iostream>
#include <vector>

struct RGB {
    unsigned char red;
    unsigned char green;
    unsigned char blue;

    RGB(unsigned char red, unsigned char green,
        unsigned char blue) : red(red), green(green), blue(blue) {
    }
};

enum class ImageType {
    PBM = 4,
    PGM,
    PPM,
    NOT_SUPPORTED,
};


class Image {
protected:
    size_t width;
    size_t height;
    uint16_t maxVal = 255;

public:
    Image(size_t width, size_t height);

    virtual size_t getWidth() const = 0;
    virtual size_t getHeight() const = 0;
    virtual size_t getSize() const = 0;

    virtual std::unique_ptr<Image> clone() const = 0;

    virtual ~Image() = default;
};


#endif //IMAGELAB_IMAGE_H