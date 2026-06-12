#ifndef IMAGELAB_ICOMMAND_H
#define IMAGELAB_ICOMMAND_H

class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;

    virtual ~ICommand() = default;
};

#endif //IMAGELAB_ICOMMAND_H