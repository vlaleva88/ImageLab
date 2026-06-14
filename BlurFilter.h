#ifndef IMAGELAB_BLURFILTER_H
#define IMAGELAB_BLURFILTER_H
#include <memory>

#include "Filter.h"


class BlurFilter : public Filter {
public:
    void visit(PBMImage& image) override;
    void visit(PGMImage& image) override;
    void visit(PPMImage& image) override;

    String getName() const override;
    std::unique_ptr<Filter> clone() const override;
};


#endif //IMAGELAB_BLURFILTER_H