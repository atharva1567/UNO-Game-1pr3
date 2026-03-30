#include "Card.h"

Card::Card() : colour(Colour::Red), value(Value::Zero) {}

Card::Card(Colour c, Value v) : colour(c), value(v) {}

Colour Card::getColour() const {
    return colour;
}

Value Card::getValue() const {
    return value;
}

std::string getValueString(Value v) {
    switch (v) {
        case Value::Zero: return "0";
        case Value::One: return "1";
        case Value::Two: return "2";
        case Value::Three: return "3";
        case Value::Four: return "4";
        case Value::Five: return "5";
        case Value::Six: return "6";
        case Value::Seven: return "7";
        case Value::Eight: return "8";
        case Value::Nine: return "9";
        case Value::Skip: return "Skip";
        case Value::Reverse: return "Reverse";
        case Value::DrawTwo: return "+2";
        case Value::WildCard: return "Wild";
        case Value::WildDrawFour: return "Wild +4";
    }
    return "?";
}

std::string getColourString(Colour c) {
    switch (c) {
        case Colour::Red: return "Red";
        case Colour::Green: return "Green";
        case Colour::Blue: return "Blue";
        case Colour::Yellow: return "Yellow";
        case Colour::Wild: return "Wild";
    }
    return "?";
}

std::string Card::toString() const {
    if (colour == Colour::Wild)
        return getValueString(value);
    return getColourString(colour) + " " + getValueString(value);
}
