#include "AddFilterCommand.h"

#include "FilterFactory.hpp"

AddFilterCommand::AddFilterCommand(int imageIndex, const String &filter) : imageIndex(imageIndex),
                                                                           filterName(filter) {
}

void AddFilterCommand::execute(ImageManager &manager) {
    auto filter = FilterFactory::create(filterName);
    manager.addFilter(imageIndex, std::move(filter));
}