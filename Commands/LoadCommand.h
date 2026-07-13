#ifndef IMAGELAB_LOADCOMMAND_H
#define IMAGELAB_LOADCOMMAND_H

#include "../Commands/ICommand.h"
#include "ImageManager.h"


class LoadCommand : public ICommand {
    String filename;

public:
    LoadCommand(const String& filename);
    void execute(ImageManager& manager) override;
};


#endif //IMAGELAB_LOADCOMMAND_H
