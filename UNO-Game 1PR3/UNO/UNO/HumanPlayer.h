#pragma once
#include "Player.h"

class HumanPlayer : public Player {
public:
    int chooseCardIndex(const Card& top, Colour currentColour) override;
    void showHand() const override;
};
