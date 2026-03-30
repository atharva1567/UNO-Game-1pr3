#include "HumanPlayer.h"
#include "UI.h"
#include <iostream>

int HumanPlayer::chooseCardIndex(const Card& top, Colour currentColour) {
    std::cout << "\nYour hand:\n";
    showHand();
    std::cout << "\nChoose card index or -1 to draw: ";
    int idx;
    std::cin >> idx;
    return idx;
}

void HumanPlayer::showHand() const {
    for (int i = 0; i < (int)hand.size(); ++i) {
        std::cout << "[" << i << "] ";
        printColoredCard(hand[i]);
        std::cout << "\n";
    }
}