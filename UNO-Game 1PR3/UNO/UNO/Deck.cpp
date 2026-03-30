#include "Deck.h"
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck() {
    reset();
}

void Deck::reset() {
    cards.clear();

    // Standard-ish UNO deck (simplified)
    for (int c = 0; c <= 3; ++c) { // Red, Green, Blue, Yellow
        for (int v = 0; v <= (int)Value::DrawTwo; ++v) {
            cards.emplace_back(static_cast<Colour>(c), static_cast<Value>(v));
            if (v != (int)Value::Zero) {
                cards.emplace_back(static_cast<Colour>(c), static_cast<Value>(v));
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        cards.emplace_back(Colour::Wild, Value::WildCard);
        cards.emplace_back(Colour::Wild, Value::WildDrawFour);
    }

    shuffle();
    index = 0;
}

void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

Card Deck::draw() {
    if (index >= (int)cards.size()) {
        reset();
    }
    return cards[index++];
}

bool Deck::isEmpty() const {
    return index >= (int)cards.size();
}