#pragma once
#include <string>

enum class Colour {
    Red,
    Green,
    Blue,
    Yellow,
    Wild
};

enum class Value {
    Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
    Skip, Reverse, DrawTwo,
    WildCard, WildDrawFour
};

class Card {
public:
    Card();
    Card(Colour c, Value v);

    Colour getColour() const;
    Value getValue() const;

    std::string toString() const;

private:
    Colour colour;
    Value value;
};

std::string getValueString(Value v);
std::string getColourString(Colour c);
