#pragma once
#include <iostream>
#include <string>
#include "Card.h"

// ANSI colors
const std::string RESET = "\033[0m";
const std::string BOLD  = "\033[1m";

inline std::string colourToAnsi(Colour c) {
    switch (c) {
        case Colour::Red:    return "\033[31m";
        case Colour::Green:  return "\033[32m";
        case Colour::Blue:   return "\033[34m";
        case Colour::Yellow: return "\033[33m";
        case Colour::Wild:   return "\033[37m"; // white
    }
    return "\033[37m";
}

inline void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

// Restores the missing function
inline void banner(const std::string& text) {
    std::cout << "\n====================\n";
    std::cout << "  " << text << "\n";
    std::cout << "====================\n";
}

// Restores the missing function
inline void printColoredCard(const Card& c) {
    Colour col = c.getColour();
    std::string ansi = colourToAnsi(col);
    std::cout << ansi << c.toString() << RESET;
}
