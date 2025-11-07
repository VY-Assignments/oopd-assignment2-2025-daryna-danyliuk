#include "Block.h"

Block::Block() : xCoord(0), yCoord(0), colour(Colour::None)
{
}
Block::Block(int x, int y, Colour colour)
    : xCoord(x), yCoord(y), colour(colour) {

}

int Block::getXCoord() const{
    return xCoord;
}

void Block::setXCoord(int x) {
    xCoord = x;
}

int Block::getYCoord() const{
    return yCoord;
}

void Block::setYCoord(int y) {
    yCoord = y;
}
