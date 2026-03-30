#pragma once
#include <iostream>
#include "UI.h"

inline void showStartMenu() {
    clearScreen();

    // Colors
    const std::string RED   = "\033[31m";
    const std::string YEL   = "\033[33m";
    const std::string WHITE = "\033[37m";
    const std::string RESET = "\033[0m";

    // Top border
    std::cout << RED << "╔══════════════════════════════════════════════╗\n";

    // Empty line
    std::cout << RED << "║" << WHITE << "                                              " << RED << "║\n";

    // UNO line (yellow UNO, everything else controlled)
    std::cout << RED << "║" 
              << WHITE << "                    "
              << YEL  << "U N O"
              << WHITE << "                     "
              << RED   << "║\n";

    // Spacer
    std::cout << RED << "║" << WHITE << "                                              " << RED << "║\n";

    // Creators label
    std::cout << RED << "║" << WHITE << "                  Creators:                   " << RED << "║\n";

    // Names horizontal
    std::cout << RED << "║" << WHITE << "          Atharva G, Adam C, Juan R           " << RED << "║\n";

    // Spacer
    std::cout << RED << "║" << WHITE << "                                              " << RED << "║\n";

    // Menu options
    std::cout << RED << "║" << WHITE << "                  1. Play                     " << RED << "║\n";
    std::cout << RED << "║" << WHITE << "                  2. Rules                    " << RED << "║\n";
    std::cout << RED << "║" << WHITE << "                  3. Exit                     " << RED << "║\n";

    // Spacer
    std::cout << RED << "║" << WHITE << "                                              " << RED << "║\n";

    // Bottom border
    std::cout << RED << "╚══════════════════════════════════════════════╝\n" << RESET;

    std::cout << "\nEnter your choice: ";
}

inline void showRulesScreen() {
    clearScreen();

    std::cout << "\033[1;37m";
    std::cout << "==================== RULES ====================\n";
    std::cout << "\033[0m";

    std::cout << " - Match cards by COLOR or NUMBER.\n";
    std::cout << " - Wild cards can be played at any time.\n";
    std::cout << " - +2 forces opponent to draw 2 cards.\n";
    std::cout << " - Wild +4 forces opponent to draw 4 cards.\n";
    std::cout << " - First player to empty their hand wins.\n\n";

    std::cout << "Press ENTER to return to menu...";
    std::cin.ignore();
    std::cin.get();
}