#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include <vector>

class GameModel {
private:
    std::vector<std::vector<char>> board;
    std::vector<std::vector<std::vector<char>>> history;

public:
    GameModel();
    const std::vector<std::vector<char>>& getBoard() const;
    bool validMove(int row, int col);
    bool boardFull();
    bool makeMove(int row, int col, char currentPlayer);
    void undoMove(char& player);
    char checkWinner();
};

#endif // GAMEMODEL_HPP
