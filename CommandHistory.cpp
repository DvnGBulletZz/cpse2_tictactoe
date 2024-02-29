#include "CommandHistory.hpp"

void CommandHistory::execute(std::unique_ptr<Command> cmd) {
    cmd->execute();
    history.push_back(std::move(cmd));
}

void CommandHistory::undo() {
    if (!history.empty()) {
        history.back()->unexecute();
        history.pop_back();
    }
}
