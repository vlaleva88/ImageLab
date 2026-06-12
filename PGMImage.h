#ifndef IMAGELAB_PGMIMAGE_H
#define IMAGELAB_PGMIMAGE_H

#include "Image.h"


class PGMImage : public Image {
    // static constexpr int MAX_VAL_PGM = 255;

    std::vector<unsigned char> pixels;

public:
    // PGMImage() = default;
    // PGMImage(size_t width, size_t height);
    PGMImage(const std::string& filename);

    size_t getWidth() const override;
    size_t getHeight() const override;
    size_t getSize() const override;

    std::unique_ptr<Image> clone() const override;

};


#endif //IMAGELAB_PGMIMAGE_H