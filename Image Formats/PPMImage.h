#ifndef IMAGELAB_PPMIMAGE_H
#define IMAGELAB_PPMIMAGE_H

#include "Image.h"
#include "Vector.hpp"


class PPMImage : public Image {
    unsigned short maxVal;
    Vector<RGB> pixels;

public:
    PPMImage(const String &filename);

    void accept(ImageVisitor& visitor) override;

    size_t getWidth() const override;
    size_t getHeight() const override;
    size_t getSize() const override;
    unsigned short getMaxVal() const;

    Vector<RGB>& getPixels();
    RGB getPixel(size_t index) const;
    void setPixel(size_t index, const RGB& value);

    unsigned short getRed(size_t index);
    unsigned short getGreen(size_t index);
    unsigned short getBlue(size_t index);

    void save(std::ostream& os) const override;

    std::unique_ptr<Image> clone() const override;

};


#endif //IMAGELAB_PPMIMAGE_H
