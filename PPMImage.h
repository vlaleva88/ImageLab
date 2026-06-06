#ifndef IMAGELAB_PPMIMAGE_H
#define IMAGELAB_PPMIMAGE_H

#include "Image.h"


class PPMImage : public Image {
    static constexpr int MAX_VAL_PPM = 256;

    std::vector<RGB> pixels;

public:
    PPMImage(size_t width, size_t heigh);

    size_t getWidth() const override;
    size_t getHeight() const override;
    size_t getSize() const override;

    std::unique_ptr<Image> clone() const override;

    // void readPixels(const std::string& filename);
};


#endif //IMAGELAB_PPMIMAGE_H