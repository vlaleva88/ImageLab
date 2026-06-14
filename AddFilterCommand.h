#ifndef IMAGELAB_ADDFILTERCOMMAND_H
#define IMAGELAB_ADDFILTERCOMMAND_H

#include "ICommand.h"


class AddFilterCommand : public ICommand {
    int imageIndex;
    String filterName;

public:
    AddFilterCommand(int imageIndex, const String& filter);

    void execute(ImageManager& manager) override;
};


#endif //IMAGELAB_ADDFILTERCOMMAND_H