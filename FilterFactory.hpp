#pragma once
#include <memory>

#include "BlurFilter.h"
#include "Filter.h"
#include "GreyscaleFilter.h"
#include "NegativeFilter.h"
#include "SharpenFilter.h"
#include "SobelFilter.h"
#include "String.h"
#include "ThresholdFilter.h"

class FilterFactory {
public:
    static std::unique_ptr<Filter> create(const String& filterName) {
        if (filterName == "greyscale") {
            return std::make_unique<GreyscaleFilter>();
        }
        if (filterName == "blur") {
            return std::make_unique<BlurFilter>();
        }
        if (filterName == "sobel") {
            return std::make_unique<SobelFilter>();
        }
        if (filterName == "negative") {
            return std::make_unique<NegativeFilter>();
        }
        if (filterName == "sharpen") {
            return std::make_unique<SharpenFilter>();
        }
        if (filterName == "threshold") {
            return std::make_unique<ThresholdFilter>();
        }
        throw std::runtime_error("Unknown filter name");
    }
};
