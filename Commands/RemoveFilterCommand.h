#ifndef IMAGELAB_REMOVEFILTERCOMMAND_H
#define IMAGELAB_REMOVEFILTERCOMMAND_H

#include "../Commands/ICommand.h"


class RemoveFilterCommand : public ICommand {
    size_t imageIndex;
    size_t filterIndex;

public:
    RemoveFilterCommand(size_t imageIndex, size_t filterIndex);

    void execute(ImageManager& manager) override;
};


#endif //IMAGELAB_REMOVEFILTERCOMMAND_H
