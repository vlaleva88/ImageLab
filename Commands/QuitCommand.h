#ifndef IMAGELAB_QUITCOMMAND_H
#define IMAGELAB_QUITCOMMAND_H

#include "ICommand.h"
#include "ImageManager.h"


class QuitCommand : public ICommand {
    bool& running;

public:
    QuitCommand(bool& running);
    void execute(ImageManager& manager) override;
};


#endif //IMAGELAB_QUITCOMMAND_H
