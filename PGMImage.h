#ifndef IMAGELAB_PGMIMAGE_H
#define IMAGELAB_PGMIMAGE_H

#include "Image.h"
#include "Vector.hpp"


class PGMImage : public Image {
    unsigned short maxVal;
    Vector<unsigned short> pixels;

public:
    PGMImage(const String& filename);

    void accept(ImageVisitor& visitor) override;

    Vector<unsigned short>& getPixels();
    unsigned short getPixel(size_t index) const;
    void setPixel(size_t index, unsigned short value);

    size_t getWidth() const override;
    size_t getHeight() const override;
    size_t getSize() const override;
    unsigned short getMaxVal() const;

    std::unique_ptr<Image> clone() const override;
};


#endif //IMAGELAB_PGMIMAGE_H