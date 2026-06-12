#ifndef IMAGELAB_ICOMMAND_H
#define IMAGELAB_ICOMMAND_H

#include "Image.h"

class ICommand {
protected:
    Image& image;
public:
    explicit ICommand (Image& image);

    virtual void execute() = 0;
    virtual void undo() = 0;

    virtual ~ICommand() = default;
};

#endif //IMAGELAB_ICOMMAND_H