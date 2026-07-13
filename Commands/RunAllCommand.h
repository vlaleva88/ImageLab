#ifndef IMAGELAB_RUNALLCOMMAND_H
#define IMAGELAB_RUNALLCOMMAND_H

#include "../Commands/ICommand.h"


class RunAllCommand : public ICommand {
public:
    void execute(ImageManager &manager) override;
};


#endif //IMAGELAB_RUNALLCOMMAND_H
