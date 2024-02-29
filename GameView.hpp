


#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP
#include <iostream>
#include "GameModel.hpp"
#include "CommandHistory.hpp"

#include <vector>

#ifdef SFML_VERSION
#include <SFML\Graphics.hpp>

#endif

class GameView {
public:
    GameView(bool createWindow);

#ifdef SFML_VERSION
    void displayBoard(const std::vector<std::vector<char>>& board);
    bool undoButtonClicked();
    void displayCurrentPlayer(char currentPlayer);
    void displayWinner(char winner);
    void displayInvalidMove();
    void close();
    bool isOpen();
    bool pollEvent(sf::Event& event);
    sf::Vector2i mousePos();
#endif
    void printBoard(const std::vector<std::vector<char>>& board);
    void printWinner(char winner);
    void printInvalidMove();


private:
#ifdef SFML_VERSION
    sf::RenderWindow window;
    sf::Font font;
    sf::Text undoText;
    sf::RectangleShape undoButton;
    sf::Text currentPlayerText;
#endif
};

#endif