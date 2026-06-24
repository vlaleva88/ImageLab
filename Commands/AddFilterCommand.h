#ifndef IMAGELAB_ADDFILTERCOMMAND_H
#define IMAGELAB_ADDFILTERCOMMAND_H

#include "ICommand.h"
#include "Filter.h"


class AddFilterCommand : public ICommand {
    int imageIndex;
    std::unique_ptr<Filter> filter;

public:
    AddFilterCommand(int imageIndex, std::unique_ptr<Filter> filter);

    void execute(ImageManager& manager) override;
};


#endif //IMAGELAB_ADDFILTERCOMMAND_H
