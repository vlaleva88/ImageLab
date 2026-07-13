#include "ImageManager.h"

#include "../Utils/Filter.h"
#include "ImageFactory.hpp"
#include "ImageWriter.h"

String ImageManager::
generateOutputName(const String &filename,
                                        const Vector<std::unique_ptr<Filter>> &filters) {
    const String& result = filename;
    size_t pos = result.findLastOf('.');

    String name = result.substr(0, pos);
    String extension = result.substr(pos, 4);

    for (size_t i = 0; i < filters.size(); i++) {
        name += "_" + filters[i]->getName();
    }
    return name + extension;
}

void ImageManager::load(const String &filename) {
    ImageRecord record;

    record.original = ImageFactory::create(filename);
    record.filtered = nullptr;
    record.filename = filename;

    images.pushBack(std::move(record));
    std::cout << "Loaded image #" << images.size() - 1 << ": " << filename << std::endl;
}

void ImageManager::addFilter(int imageIndex, std::unique_ptr<Filter> filter) {
    if (imageIndex >= images.size()) {
        throw std::invalid_argument("Image index out of range");
    }

    std::cout << "Added filter " << filter->getName() << " to image # " << imageIndex << std::endl;
    images[imageIndex].filters.pushBack(std::move(filter));
}

void ImageManager::removeFilter(int imageIndex, size_t filter) {
    if (imageIndex >= images.size()) {
        throw std::invalid_argument("Image index out of range");
    }

    std::cout << "Removed filter " << images[imageIndex].filters[filter]->getName()
    << " from image # " << imageIndex << std::endl;
    images[imageIndex].filters.remove(filter);
}

void ImageManager::showFilters(size_t imageIndex) const {
    if (imageIndex >= images.size()) {
        throw std::invalid_argument("Image index out of range");
    }
    std::cout << "Filters showed from image # " << imageIndex << std::endl;
    if (images[imageIndex].filters.empty()) {
        std::cout << "No added filters\n";
        return;
    }
    for (size_t i = 0; i < images[imageIndex].filters.size(); i++) {
        std::cout << images[imageIndex].filters[i]->getName() << "\n";
    }
}

void ImageManager::showAllFilters() const {
    if (images.empty()) {
        std::cout << "No added filters\n";
        return;
    }
    for (size_t i = 0; i < images.size(); i++) {
        showFilters(i);
    }
}

void ImageManager::run(int imageIndex) {
    if (imageIndex >= images.size()) {
        throw std::runtime_error("Invalid image index");
    }

    ImageRecord& record = images[imageIndex];

    record.filtered = record.original->clone();

    for (size_t i = 0; i < images[imageIndex].filters.size(); i++) {
        record.filtered->accept(*record.filters[i]);
    }

    std::cout << "Processed image #" << imageIndex << std::endl;
}

void ImageManager::runAll() {
    if (images.empty()) {
        throw std::runtime_error("No loaded images");
    }
    for (size_t i = 0; i < images.size(); i++) {
        run(i);
    }
    std::cout << "Processed all images" << std::endl;
}

void ImageManager::save(int imageIndex, const String &outputName) {
    if (imageIndex >= images.size()) {
        throw std::invalid_argument("Image index out of range");
    }

    ImageRecord& record = images[imageIndex];
    if (!record.filtered) {
        run(imageIndex);
    }

    String finalName = outputName;
    if (finalName.isEmpty()) {
        finalName = generateOutputName(record.filename, record.filters);
    }
    ImageWriter::write(*record.filtered, finalName);

    std::cout << "Saved image #" << imageIndex << "as " << finalName << std::endl;
}
