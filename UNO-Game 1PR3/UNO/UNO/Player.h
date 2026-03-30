#pragma once
#include <vector>
#include "Card.h"

class Player {
public:
    virtual ~Player() = default;

    void addCard(const Card& c);
    Card removeCard(int idx);
    int handSize() const;
    const Card& getCard(int idx) const;

    virtual int chooseCardIndex(const Card& top, Colour currentColour) = 0;
    virtual void showHand() const;

protected:
    std::vector<Card> hand;
};
