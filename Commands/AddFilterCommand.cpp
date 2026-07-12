#include "../Commands/AddFilterCommand.h"

#include "FilterFactory.hpp"

AddFilterCommand::AddFilterCommand(int imageIndex, std::unique_ptr<Filter> filter) : imageIndex(imageIndex),
                                                                           filter(std::move(filter)) {
}

void AddFilterCommand::execute(ImageManager &manager) {
    // auto filter = FilterFactory::create(filterName);
    // manager.addFilter(imageIndex, std::move(filter));
    manager.addFilter(imageIndex, std::move(filter));
}
