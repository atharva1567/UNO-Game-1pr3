#pragma once
#include "Deck.h"
#include "HumanPlayer.h"
#include "BotPlayer.h"

class Game {
public:
    Game();
    void start();

private:
    Deck deck;
    HumanPlayer human;
    BotPlayer bot;
    Card topCard;
    Colour currentColour;
    bool gameOver;
    bool humanTurn;

    bool canPlay(const Card& c) const;
    void applyCardEffect(const Card& c, bool isHumanTurn);
};
