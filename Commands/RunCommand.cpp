#include "../Commands/RunCommand.h"

RunCommand::RunCommand(size_t imageIndex) : imageIndex(imageIndex) {
}

void RunCommand::execute(ImageManager &manager) {
    manager.run(imageIndex);
}
