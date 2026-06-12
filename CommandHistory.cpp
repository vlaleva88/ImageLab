#include "CommandHistory.h"


void CommandHistory::add(std::unique_ptr<ICommand> command) {
    history.push_back(std::move(command));
}

void CommandHistory::undoLast() {
    if (!history.empty()) {
        history.back()->undo();
        history.pop_back();
    }
    else {
        throw std::logic_error("Command history is empty");
    }
}
