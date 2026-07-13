#include "../Commands/ShowAllFiltersCommand.h"

void ShowAllFiltersCommand::execute(ImageManager &manager) {
    manager.showAllFilters();
}
