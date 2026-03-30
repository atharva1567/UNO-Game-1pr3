#include "Player.h"
#include <iostream>

void Player::addCard(const Card& c) {
    hand.push_back(c);
}

Card Player::removeCard(int idx) {
    Card c = hand[idx];
    hand.erase(hand.begin() + idx);
    return c;
}

int Player::handSize() const {
    return (int)hand.size();
}

const Card& Player::getCard(int idx) const {
    return hand[idx];
}

void Player::showHand() const {
    for (int i = 0; i < (int)hand.size(); ++i) {
        std::cout << "[" << i << "] " << hand[i].toString() << "\n";
    }
}