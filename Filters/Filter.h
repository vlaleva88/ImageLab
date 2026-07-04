#ifndef IMAGELAB_FILTER_H
#define IMAGELAB_FILTER_H

#include "../Utils/Image.h"

class Filter : public ImageVisitor {
public:
    virtual String getName() const = 0;
    virtual std::unique_ptr<Filter> clone() const = 0;
    virtual ~Filter() = default;
};

#endif //IMAGELAB_FILTER_H
