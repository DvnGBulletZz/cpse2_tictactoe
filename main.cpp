#include "GameController.hpp"

using namespace std;

int main() {
    std::string userInput;
    #ifdef SFML_VERSION
    
    std::cout << "Enter 'console' to play in console or 'ui' to play in a windowed mode with a ui: ";
    std::cin >> userInput;

    #else
        userInput = "console";
        std::cout << "SFML not enabled(you are probably on microcontroller), playing in console mode" << std::endl;
    #endif
    
    
    if (userInput == "console") {
        GameController game(false);
        game.playGameConsole();
    } 
#ifdef SFML_VERSION
    else if (userInput == "ui") {
        GameController game(true);
        game.playGame();
    } 
#endif

    return 0;
}
