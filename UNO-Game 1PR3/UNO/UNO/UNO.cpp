#include "Game.h"
#include "Menu.h"

int main() {
    while (true) {
        showStartMenu();

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            Game game;
            game.start();
        }
        else if (choice == 2) {
            std::cin.ignore();
            showRulesScreen();
        }
        else if (choice == 3) {
            clearScreen();
            std::cout << "Thanks for playing UNO!\n";
            return 0;
        }
        else {
            std::cout << "Invalid choice.\n";
        }
    }
}