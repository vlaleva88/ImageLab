#ifndef IMAGELAB_SOBELFILTER_H
#define IMAGELAB_SOBELFILTER_H

#include "Filter.h"


class SobelFilter : public Filter {
    static constexpr int KERNEL_GX[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    static constexpr int KERNEL_GY[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

public:
    void visit(PPMImage &image) override;
    void visit(PGMImage &image) override;
    void visit(PBMImage &image) override;

    String getName() const override;

    std::unique_ptr<Filter> clone() const override;
};


#endif //IMAGELAB_SOBELFILTER_H
