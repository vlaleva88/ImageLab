#ifndef IMAGELAB_SHOWFILTERSCOMMAND_H
#define IMAGELAB_SHOWFILTERSCOMMAND_H

#include "../Commands/ICommand.h"


class ShowFiltersCommand : public ICommand {
    size_t imageIndex;

public:
    ShowFiltersCommand(size_t image);
    void execute(ImageManager& manager) override;
};


#endif //IMAGELAB_SHOWFILTERSCOMMAND_H
