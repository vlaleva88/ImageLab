#include "SaveCommand.h"

#include <utility>

SaveCommand::SaveCommand(size_t imageIdex, String name) :
imageIdex(imageIdex), outputName(std::move(name)) {
}

void SaveCommand::execute(ImageManager &manager) {
    manager.save(imageIdex, outputName);
}
