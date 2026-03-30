#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Gui {
public:
    Gui(Game& game);

    void run();

private:
    Game& game;
    sf::RenderWindow window;

    // Drawing helpers
    void drawGame();
    void drawCard(const Card& card, float x, float y, bool faceUp = true);
    void drawPlayerHand();
    void drawBotHand();
    void drawTopCard();
    void drawDeck();

    // Input helpers
    void handleMouseClick(int x, int y);
};