#include "BotPlayer.h"

int BotPlayer::chooseCardIndex(const Card& top, Colour currentColour) {
    for (int i = 0; i < (int)hand.size(); ++i) {
        const Card& c = hand[i];
        if (c.getColour() == currentColour ||
            c.getValue() == top.getValue() ||
            c.getColour() == Colour::Wild) {
            return i;
        }
    }
    return -1; // draw
}
