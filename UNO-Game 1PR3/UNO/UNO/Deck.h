#pragma once
#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();

    void reset();
    void shuffle();
    Card draw();
    bool isEmpty() const;

private:
    std::vector<Card> cards;
    int index;
};
