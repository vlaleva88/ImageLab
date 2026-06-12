#ifndef IMAGELAB_PPMIMAGE_H
#define IMAGELAB_PPMIMAGE_H

#include "Image.h"


class PPMImage : public Image {
    std::vector<RGB> pixels;

public:
    PPMImage(const std::string &filename);

    size_t getWidth() const override;
    size_t getHeight() const override;
    size_t getSize() const override;

    std::unique_ptr<Image> clone() const override;

};


#endif //IMAGELAB_PPMIMAGE_H