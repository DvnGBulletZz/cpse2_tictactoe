#include "GameModel.hpp"

GameModel::GameModel(): board(3, std::vector<char>(3, ' ')) {}

const std::vector<std::vector<char>>& GameModel::getBoard() const {
    return board;
}

bool GameModel::validMove(int row, int col) {
    if ((row >= 0 && row < 3) && (col >= 0 && col < 3) && (board[row][col] == ' ')) {
        return true;
    }
    if ((board[row][col] == 'X') || (board[row][col] == 'O')) {
        return false;
    }
    return false;
}

bool GameModel::boardFull() {
    for (auto& row : board) {
        for (auto& cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool GameModel::makeMove(int row, int col, char currentPlayer) {
    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        history.push_back(board);
        return true;
    }
    return false;
}

void GameModel::undoMove(char& player) {
    if (!history.empty()) {
        history.pop_back();
        if (!history.empty()) {
            board = history.back();
        } else {
            board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
        }
    }
    player = (player == 'X') ? 'O' : 'X';
}

char GameModel::checkWinner() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}
