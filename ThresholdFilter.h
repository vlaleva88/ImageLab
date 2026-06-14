#ifndef IMAGELAB_THRESHOLDFILTER_H
#define IMAGELAB_THRESHOLDFILTER_H

#include "Filter.h"


class ThresholdFilter : public Filter {
    static constexpr int THRESHOLD = 128;
    static constexpr unsigned short UNDER_THRESHOLD = 0;
    static constexpr unsigned short OVER_THRESHOLD = 255;

public:
    void visit(PGMImage &image) override;
    void visit(PPMImage &image) override;
    void visit(PBMImage &image) override;

    String getName() const override;

    std::unique_ptr<Filter> clone() const override;
};


#endif //IMAGELAB_THRESHOLDFILTER_H