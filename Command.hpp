#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "GameModel.hpp"

class Command {
public:
    virtual void execute() = 0;
    virtual void unexecute() = 0;
};

class MoveCommand : public Command {
private:
    GameModel& model;
    int row, col;
    char& player;

public:
    MoveCommand(GameModel& model, int row, int col, char& player);
    void execute() override;
    void unexecute() override;
};

#endif // COMMAND_HPP
