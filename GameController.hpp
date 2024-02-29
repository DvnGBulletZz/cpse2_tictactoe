#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "GameView.hpp"
#include "GameModel.hpp"
#include "CommandHistory.hpp"
#include "Command.hpp"
#include <memory>

class GameController {
public:
    GameController(bool createWindow = false);
    

    void playGame();
    void playGameConsole();


private:
    bool createWindow;
    GameView view;
    GameModel model;
    CommandHistory commandHistory;
    char currentPlayer = 'X';
    char winner = ' ';
};

#endif