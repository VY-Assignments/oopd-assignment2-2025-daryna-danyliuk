#include "Block.h"

Block::Block(int x, int y, std::string colour)
    : xCoord(x), yCoord(y), colour(colour) {

}

int Block::getXCoord() {
    return xCoord;
}

void Block::setXCoord(int x) {
    xCoord = x;
}

int Block::getYCoord() {
    return yCoord;
}

void Block::setYCoord(int y) {
    yCoord = y;
}
