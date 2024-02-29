#include "GameView.hpp"


#ifdef SFML_VERSION
GameView::GameView(bool createWindow): window(sf::VideoMode(300,400), "Tic Tac Toe"), undoText("undo", font , 20), undoButton(sf::Vector2f(150,50)) {
    if (!createWindow) {
        window.close();
    } else {
        if (!font.loadFromFile("coolfont.ttf")) {
            std::cout << "Error loading font" << std::endl;
        }
        
        currentPlayerText.setFont(font);
        currentPlayerText.setStyle(sf::Text::Bold);
        currentPlayerText.setCharacterSize(20);
        currentPlayerText.setPosition(20, 320);

        undoButton.setFillColor(sf::Color::White);
        undoButton.setOutlineColor(sf::Color::Black);
        undoButton.setOutlineThickness(3);
        undoButton.setPosition(75, 350);
        undoButton.setSize(sf::Vector2f(150, 50));

        undoText.setPosition(120, 360);
        undoText.setFillColor(sf::Color::Black);
        undoText.setFont(font);
        undoText.setStyle(sf::Text::Bold);
        undoText.setCharacterSize(20);
    }
}




void GameView::displayBoard(const std::vector<std::vector<char>>& board) {
    window.clear();

    // draw board
    for(int i = 0; i < 3; i++) {
        sf::Vertex lines[] = {
            sf::Vertex(sf::Vector2f(100 * i, 0)),
            sf::Vertex(sf::Vector2f(100 * i, 300)),
            sf::Vertex(sf::Vector2f(0, 100 * i)),
            sf::Vertex(sf::Vector2f(300, 100 * i))
        };
        window.draw(lines, 4, sf::Lines);
    }
        

    // draw X's and O's
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            sf::Text text(board[i][j], font, 50);
            text.setPosition(100 * j + 25, 100 * i + 25);
            window.draw(text);
        }
    }

    window.draw(undoButton);
    window.draw(undoText);
    window.draw(currentPlayerText);
    window.display();
}

bool GameView::undoButtonClicked() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (undoButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        return true;
    }
    return false;
}

void GameView::displayCurrentPlayer(char currentPlayer) {
    currentPlayerText.setString("Current Player: " + std::string(1, currentPlayer));
}

void GameView::displayWinner(char winner) {
    if (winner == 't') {
        currentPlayerText.setString("Tie Game");
    } else {
        currentPlayerText.setString("Winner: " + std::string(1, winner));
    }
}

void GameView::displayInvalidMove() {
    currentPlayerText.setString("Invalid Move");
}

void GameView::close() {
    window.close();
}

bool GameView::isOpen() {
    return window.isOpen();
}

bool GameView::pollEvent(sf::Event& event) {
    return window.pollEvent(event);
}

sf::Vector2i GameView::mousePos() {
    return sf::Mouse::getPosition(window);
}
#else

GameView::GameView(bool createWindow) {}

#endif


void GameView::printBoard(const std::vector<std::vector<char>>& board) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "---------" << std::endl;
        }
    }
}

void GameView::printWinner(char winner) {
    if (winner == 't') {
        std::cout << "Tie Game" << std::endl;
    } else {
        std::cout << "Winner: " << winner << std::endl;
    }
}

void GameView::printInvalidMove() {
    std::cout << "Invalid Move" << std::endl;
}
