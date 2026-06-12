#ifndef IMAGELAB_COMMANDHISTORY_H
#define IMAGELAB_COMMANDHISTORY_H

#include <memory>
#include <vector>

#include "ICommand.h"


class CommandHistory {
    std::vector<std::unique_ptr<ICommand>> history;

public:
    void add(std::unique_ptr<ICommand> command);
    void undoLast();
};


#endif //IMAGELAB_COMMANDHISTORY_H