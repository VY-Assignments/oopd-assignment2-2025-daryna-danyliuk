#include "Block.h"

Block::Block() : localX(0), localY(0), colour(Colour::None)
{
}
Block::Block(float x, float y, Colour colour)
    : localX(x), localY(y), colour(colour) {

}

int Block::getLocalX() const{
    return localX;
}

void Block::setLocalX(int x) {
    localX = x;
}

int Block::getLocalY() const{
    return localY;
}

void Block::setLocalY(int y) {
    localY = y;
}
Colour Block::getColour() {
    return colour;
}