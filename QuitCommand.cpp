#include "QuitCommand.h"

QuitCommand::QuitCommand(bool &running) : running(running) {
}

void QuitCommand::execute(ImageManager &manager) {
    running = false;
    std::cout << "Quitting..." << std::endl;
}
