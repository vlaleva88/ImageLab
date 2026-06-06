#ifndef IMAGELAB_PBMIMAGE_H
#define IMAGELAB_PBMIMAGE_H

#include "Image.h"


class PBMImage : public Image {
    std::vector<bool> pixels;

public:
    PBMImage(size_t width, size_t height);

    size_t getWidth() const override;
    size_t getHeight() const override;
    size_t getSize() const override;

    std::unique_ptr<Image> clone() const override;
};


#endif //IMAGELAB_PBMIMAGE_H