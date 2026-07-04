#ifndef IMAGELAB_GREYSCALEFILTER_H
#define IMAGELAB_GREYSCALEFILTER_H

#include "../Filters/Filter.h"


class GreyscaleFilter : public Filter {
public:
    void visit(PPMImage& image) override;
    void visit(PBMImage& image) override;
    void visit(PGMImage &image) override;

    String getName() const override;

    std::unique_ptr<Filter> clone() const override;
};


#endif //IMAGELAB_GREYSCALEFILTER_H
