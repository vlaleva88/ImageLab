#include "LoadCommand.h"

LoadCommand::LoadCommand(const String &filename) : filename(filename) {
}

void LoadCommand::execute(ImageManager &manager) {
    manager.load(filename);
}
