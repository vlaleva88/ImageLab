#include "../Commands/RemoveFilterCommand.h"

RemoveFilterCommand::RemoveFilterCommand(size_t imageIndex, size_t filterIndex)
: imageIndex(imageIndex), filterIndex(filterIndex) {
}

void RemoveFilterCommand::execute(ImageManager &manager) {
    manager.removeFilter(imageIndex, filterIndex);
}
