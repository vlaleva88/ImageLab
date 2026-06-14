#ifndef IMAGELAB_ICOMMAND_H
#define IMAGELAB_ICOMMAND_H

#include "ImageManager.h"

class ICommand {
public:
    virtual void execute(ImageManager& manager) = 0;
    virtual ~ICommand() = default;
};

#endif //IMAGELAB_ICOMMAND_H