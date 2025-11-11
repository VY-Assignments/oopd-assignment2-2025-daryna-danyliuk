#include "Block.h"

Block::Block() : localX(0), localY(0), colour(Colour::None)
{
}
Block::Block(float x, float y, Colour colour)
    : localX(x), localY(y), colour(colour) {
}

float Block::getLocalX() const{
    return localX;
}

void Block::setLocalX(float x) {
    localX = x;
}

float Block::getLocalY() const{
    return localY;
}

void Block::setLocalY(float y) {
    localY = y;
}
Colour Block::getColour() {
    return colour;
}