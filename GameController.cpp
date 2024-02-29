#include "GameController.hpp"

GameController::GameController(bool createWindow): createWindow(createWindow), view(createWindow) {}

#ifdef SFML_VERSION
void GameController::playGame() {
    sf::Event event;

    while (view.isOpen()) {
        while (view.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                view.close();
            } else if (event.type == sf::Event::MouseButtonPressed && winner == ' ') {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = view.mousePos();
                    if (view.undoButtonClicked()) {
                        commandHistory.undo();
                    } else {
                        int row = mousePos.y / 100;
                        int col = mousePos.x / 100;
                        if (model.validMove(row, col)) {
                            commandHistory.execute(std::make_unique<MoveCommand>(model, row, col, currentPlayer));
                            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        } else {
                            view.displayInvalidMove();
                        }
                    }
                }
            }
        }
            
        view.displayBoard(model.getBoard());
        winner = model.checkWinner();
        if (winner != ' ') {
            view.displayWinner(winner);
        } else if (model.boardFull()) {
            view.displayWinner('t');
        } else {
            view.displayCurrentPlayer(currentPlayer);
        }
    }
}
#endif
void GameController::playGameConsole() {
    std::string userInput;
    while (!model.boardFull() && winner == ' ') {
        view.printBoard(model.getBoard());
        std::cout << "Player " << currentPlayer << ", enter a row(0-2), or type 'undo': ";
        std::cin >> userInput;
        if (userInput == "undo") {
            commandHistory.undo();
        } else {
            int row = std::stoi(userInput);
            std::cout << "Player " << currentPlayer << ", enter a column(0-2): ";
            std::cin >> userInput;
            int col = std::stoi(userInput);
            if (model.validMove(row, col)) {
                commandHistory.execute(std::make_unique<MoveCommand>(model, row, col, currentPlayer));
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            } else {
                view.printInvalidMove();
            }
        }
        if (model.boardFull()) {
        winner = 't';
        } 
        else {
        winner = model.checkWinner();
        }
    }
    
    view.printBoard(model.getBoard());
    view.printWinner(winner);
}
