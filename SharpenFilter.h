#ifndef IMAGELAB_SHARPENFILTER_H
#define IMAGELAB_SHARPENFILTER_H

#include "Filter.h"


class SharpenFilter : public Filter {
    static constexpr int KERNEL[3][3] = {
        {0, -1, 0},
        {-1, 5, -1},
        {0, -1, 0}
    };

public:
    void visit(PGMImage &image) override;
    void visit(PPMImage &image) override;
    void visit(PBMImage &image) override;

    String getName() const override;

    std::unique_ptr<Filter> clone() const override;
};


#endif //IMAGELAB_SHARPENFILTER_H