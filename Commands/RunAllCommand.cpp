#include "../Commands/RunAllCommand.h"

void RunAllCommand::execute(ImageManager &manager) {
    manager.runAll();
}
