#ifndef IMAGELAB_NEGATIVEFILTER_H
#define IMAGELAB_NEGATIVEFILTER_H

#include "Filter.h"


class NegativeFilter : public Filter {
public:
    void visit(PPMImage& image) override;
    void visit(PBMImage& image) override;
    void visit(PGMImage &image) override;

    String getName() const override;

    std::unique_ptr<Filter> clone() const override;
};


#endif //IMAGELAB_NEGATIVEFILTER_H