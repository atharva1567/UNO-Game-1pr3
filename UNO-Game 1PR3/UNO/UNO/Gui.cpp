#include "Gui.h"
#include <iostream>

Gui::Gui(Game& g)
    : game(g),
      window(sf::RenderWindow(sf::VideoMode(1280, 720), "UNO - GUI Edition")) {}

void Gui::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                handleMouseClick(event.mouseButton.x, event.mouseButton.y);
            }
        }

        window.clear(sf::Color(30, 120, 60)); // UNO green
        drawGame();
        window.display();
    }
}

void Gui::drawGame() {
    drawPlayerHand();
    drawBotHand();
    drawTopCard();
    drawDeck();
}

void Gui::drawCard(const Card& card, float x, float y, bool faceUp) {
    sf::RectangleShape rect(sf::Vector2f(80, 120));
    rect.setPosition(x, y);
    rect.setOutlineThickness(3);
    rect.setOutlineColor(sf::Color::Black);

    if (!faceUp) {
        rect.setFillColor(sf::Color(50, 50, 200)); // back of card
        window.draw(rect);
        return;
    }

    // Color mapping
    sf::Color fill;
    switch (card.getColour()) {
        case Red: fill = sf::Color::Red; break;
        case Green: fill = sf::Color::Green; break;
        case Blue: fill = sf::Color::Blue; break;
        case Yellow: fill = sf::Color::Yellow; break;
        default: fill = sf::Color(200, 200, 200); break;
    }

    rect.setFillColor(fill);
    window.draw(rect);

    // Draw value text
    static sf::Font font;
    static bool loaded = false;
    if (!loaded) {
        font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf");
        loaded = true;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::Black);
    text.setString(getValueString(card.getValue()));
    text.setPosition(x + 20, y + 40);

    window.draw(text);
}

void Gui::drawPlayerHand() {
    float startX = 100;
    float y = 550;

    for (int i = 0; i < game.human->getHandSize(); i++) {
        Card* c = game.human->getCard(i);
        drawCard(*c, startX + i * 90, y, true);
    }
}

void Gui::drawBotHand() {
    float startX = 100;
    float y = 50;

    for (int i = 0; i < game.bot->getHandSize(); i++) {
        drawCard(Card(None, Zero), startX + i * 40, y, false);
    }
}

void Gui::drawTopCard() {
    drawCard(game.topCard, 600, 300, true);
}

void Gui::drawDeck() {
    sf::RectangleShape rect(sf::Vector2f(80, 120));
    rect.setPosition(450, 300);
    rect.setFillColor(sf::Color(50, 50, 200));
    rect.setOutlineThickness(3);
    rect.setOutlineColor(sf::Color::Black);
    window.draw(rect);
}

void Gui::handleMouseClick(int x, int y) {
    // TODO: detect card clicks
    std::cout << "Clicked at: " << x << ", " << y << "\n";
}