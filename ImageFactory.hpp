#pragma once

#include "Image.h"
#include "PPMImage.h"
#include "PGMImage.h"
#include "PBMImage.h"

class ImageFactory {
    static constexpr int MIN_FILE_LENGTH = 4;
public:
    static std::unique_ptr<Image> create(const String& filename) {
        if (filename.length() <= MIN_FILE_LENGTH) {
            return nullptr;
        }

        if (filename.endsWith(".pgm")) {
            return std::make_unique<PGMImage> (filename.c_str());
        }
        if (filename.endsWith(".pbm")) {
            return std::make_unique<PBMImage> (filename.c_str());
        }
        if (filename.endsWith(".ppm")) {
            return std::make_unique<PPMImage> (filename.c_str());
        }

        throw std::runtime_error("File does not exist");
    }
};