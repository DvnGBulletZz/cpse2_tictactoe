#ifndef COMMANDHISTORY_HPP
#define COMMANDHISTORY_HPP

#include <vector>
#include <memory>
#include "Command.hpp"

class CommandHistory {
private:
    std::vector<std::unique_ptr<Command>> history;

public:
    void execute(std::unique_ptr<Command> cmd);
    void undo();
};

#endif // COMMANDHISTORY_HPP
