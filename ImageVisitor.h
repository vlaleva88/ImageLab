#ifndef IMAGELAB_IMAGEVISITOR_H
#define IMAGELAB_IMAGEVISITOR_H

class PBMImage;
class PGMImage;
class PPMImage;


class ImageVisitor {
public:
    virtual void visit(PPMImage& image) = 0;
    virtual void visit(PGMImage& image) = 0;
    virtual void visit(PBMImage& image) = 0;

    virtual ~ImageVisitor() = default;
};

#endif //IMAGELAB_IMAGEVISITOR_H