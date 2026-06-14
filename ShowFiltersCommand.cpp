#include "ShowFiltersCommand.h"

ShowFiltersCommand::ShowFiltersCommand(size_t image) : imageIndex(image) {
}

void ShowFiltersCommand::execute(ImageManager &manager) {
    manager.showFilters(imageIndex);
}
