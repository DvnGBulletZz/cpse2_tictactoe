#include "Command.hpp"

MoveCommand::MoveCommand(GameModel& model, int row, int col, char& player)
    : model(model), row(row), col(col), player(player) {}

void MoveCommand::execute() {
    model.makeMove(row, col, player);
}

void MoveCommand::unexecute() {
    model.undoMove(player);
}
