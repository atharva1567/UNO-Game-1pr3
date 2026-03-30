#include "Game.h"
#include "UI.h"
#include <iostream>

Game::Game() : gameOver(false), humanTurn(true) {
    deck.reset();
}

bool Game::canPlay(const Card& c) const {
    return c.getColour() == currentColour ||
           c.getValue() == topCard.getValue() ||
           c.getColour() == Colour::Wild;
}

void Game::applyCardEffect(const Card& c, bool isHumanTurnFlag) {
    if (c.getValue() == Value::DrawTwo) {
        if (isHumanTurnFlag) {
            bot.addCard(deck.draw());
            bot.addCard(deck.draw());
        } else {
            human.addCard(deck.draw());
            human.addCard(deck.draw());
        }
    } else if (c.getValue() == Value::WildDrawFour) {
        if (isHumanTurnFlag) {
            for (int i = 0; i < 4; ++i) bot.addCard(deck.draw());
        } else {
            for (int i = 0; i < 4; ++i) human.addCard(deck.draw());
        }
    }
}

void Game::start() {
    // Deal 7 cards each
    for (int i = 0; i < 7; ++i) {
        human.addCard(deck.draw());
        bot.addCard(deck.draw());
    }

    // Initial top card
    topCard = deck.draw();
    currentColour = topCard.getColour();

    while (!gameOver) {
        clearScreen();
        banner("UNO: Human vs Bot");

        std::cout << "\nTop card: ";
        printColoredCard(topCard);
        std::cout << "\n";

        std::cout << "\nBot has " << bot.handSize() << " cards.\n";

        // ---------------- HUMAN TURN ----------------
        if (humanTurn) {
            banner("YOUR TURN");
            int idx = human.chooseCardIndex(topCard, currentColour);

            if (idx == -1) {
                Card drawn = deck.draw();
                std::cout << "You drew: ";
                printColoredCard(drawn);
                std::cout << "\n";

                if (canPlay(drawn)) {
                    std::cout << "You can play it. Playing...\n";
                    topCard = drawn;

                    if (topCard.getColour() != Colour::Wild)
                        currentColour = topCard.getColour();

                    applyCardEffect(topCard, true);
                } else {
                    human.addCard(drawn);
                }
            } else if (idx >= 0 && idx < human.handSize()) {
                Card chosen = human.getCard(idx);

                if (!canPlay(chosen)) {
                    std::cout << "You can't play that card. Press Enter.\n";
                    std::cin.ignore();
                    std::cin.get();
                    continue;
                }

                chosen = human.removeCard(idx);
                topCard = chosen;

                if (topCard.getColour() != Colour::Wild) {
                    currentColour = topCard.getColour();
                } else {
                    int choice;
                    std::cout << "Choose colour: 0=Red 1=Green 2=Blue 3=Yellow: ";
                    std::cin >> choice;
                    currentColour = static_cast<Colour>(choice);
                }

                applyCardEffect(topCard, true);
            }

            if (human.handSize() == 0) {
                clearScreen();
                banner("YOU WIN!");
                gameOver = true;
            } else {
                humanTurn = false;
            }
        }
        // ---------------- BOT TURN ----------------
        else {
            banner("BOT TURN");
            int idx = bot.chooseCardIndex(topCard, currentColour);

            if (idx == -1) {
                Card drawn = deck.draw();
                if (canPlay(drawn)) {
                    topCard = drawn;

                    if (topCard.getColour() != Colour::Wild)
                        currentColour = topCard.getColour();
                    else
                        currentColour = Colour::Red; // simple bot choice

                    applyCardEffect(topCard, false);
                    std::cout << "Bot draws and plays: ";
                    printColoredCard(topCard);
                    std::cout << "\n";
                } else {
                    bot.addCard(drawn);
                    std::cout << "Bot draws a card.\n";
                }
            } else {
                Card chosen = bot.removeCard(idx);
                std::cout << "Bot plays: ";
                printColoredCard(chosen);
                std::cout << "\n";

                topCard = chosen;

                if (topCard.getColour() != Colour::Wild)
                    currentColour = topCard.getColour();
                else
                    currentColour = Colour::Red; // simple bot choice

                applyCardEffect(topCard, false);
            }

            if (bot.handSize() == 0) {
                clearScreen();
                banner("BOT WINS!");
                gameOver = true;
            } else {
                humanTurn = true;
            }
        }

        if (!gameOver) {
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }
    }
}