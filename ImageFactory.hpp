#pragma once

#include "Image.h"
#include "PPMImage.h"
#include "PGMImage.h"
#include "PBMImage.h"

class ImageFactory {
    static constexpr int MIN_FILE_LENGTH = 4;
public:
    static std::unique_ptr<Image> create(const std::string& filename) {
        if (filename.size() <= MIN_FILE_LENGTH) {
            return nullptr;
        }

        if (filename.ends_with(".pgm")) {
            return std::make_unique<PGMImage> (filename);
        }
        if (filename.ends_with(".pbm")) {
            return std::make_unique<PBMImage> (filename);
        }
        if (filename.ends_with(".ppm")) {
            return std::make_unique<PPMImage> (filename);
        }

        throw std::runtime_error("File does not exist");
    }
};