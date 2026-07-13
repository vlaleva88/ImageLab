#ifndef IMAGELAB_SHOWALLFILTERSCOMMAND_H
#define IMAGELAB_SHOWALLFILTERSCOMMAND_H

#include "../Commands/ICommand.h"


class ShowAllFiltersCommand : public ICommand {
public:
    void execute(ImageManager& manager) override;
};


#endif //IMAGELAB_SHOWALLFILTERSCOMMAND_H
