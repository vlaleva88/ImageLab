#ifndef IMAGELAB_IMAGEMANAGER_H
#define IMAGELAB_IMAGEMANAGER_H
#include <memory>

#include "Image.h"
#include "Vector.hpp"


class Filter;

class ImageManager {
    struct ImageRecord {
        std::shared_ptr<Image> original;
        std::shared_ptr<Image> filtered;
        Vector<std::unique_ptr<Filter>> filters;
        String filename;
    };
    Vector<ImageRecord> images;

    static String generateOutputName(const String& filename,
        const Vector<std::unique_ptr<Filter>>& filters) ;

public:
    void load(const String& filename);
    void addFilter(int imageIndex, std::unique_ptr<Filter> filter);
    void removeFilter(int imageIndex, size_t filter);
    void showFilters(size_t imageIndex) const;
    void showAllFilters() const;

    void run(int imageIndex);
    void runAll();

    void save(int imageIndex, const String& outputName = "");
};


#endif //IMAGELAB_IMAGEMANAGER_H