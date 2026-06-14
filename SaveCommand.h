#ifndef IMAGELAB_SAVECOMMAND_H
#define IMAGELAB_SAVECOMMAND_H

#include "ICommand.h"


class SaveCommand : public ICommand {
    size_t imageIdex;
    String outputName;

public:
    SaveCommand(size_t imageIdex, String  name = "");
    void execute(ImageManager &manager) override;
};


#endif //IMAGELAB_SAVECOMMAND_H