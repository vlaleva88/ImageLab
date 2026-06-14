#ifndef IMAGELAB_RUNCOMMAND_H
#define IMAGELAB_RUNCOMMAND_H

#include "ICommand.h"


class RunCommand : public ICommand {
    size_t imageIndex;

public:
    RunCommand(size_t imageIndex);
    void execute(ImageManager &manager) override;
};


#endif //IMAGELAB_RUNCOMMAND_H