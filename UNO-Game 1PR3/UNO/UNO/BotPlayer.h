#pragma once
#include "Player.h"

class BotPlayer : public Player {
public:
    int chooseCardIndex(const Card& top, Colour currentColour) override;
};
