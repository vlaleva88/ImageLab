#ifndef IMAGELAB_PBMIMAGE_H
#define IMAGELAB_PBMIMAGE_H

#include "Image.h"
#include "Vector.hpp"


class PBMImage : public Image {
    Vector<bool> pixels;

public:
    explicit PBMImage (const String& filename);

    void accept(ImageVisitor& visitor) override;

    size_t getWidth() const override;
    size_t getHeight() const override;
    size_t getSize() const override;

    bool getPixel(size_t index) const;
    void setPixel(size_t index, bool value);

    void save(std::ostream& os) const override;

    std::unique_ptr<Image> clone() const override;
};


#endif //IMAGELAB_PBMIMAGE_H