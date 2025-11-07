#include "TetrominoFactory.h"

Tetromino TetrominoFactory::create(TetrominoType type) {
    std::array<Block, 4> blocks;
    Colour colour;
    std::pair<int, int> pivot = { 0, 0 };
    int startX = 5;
    int startY = 0;

    switch (type) {
    case TetrominoType::I:
        colour = Colour::Cyan;
        blocks = { Block(-1,0,colour), Block(0,0,colour), Block(1,0,colour), Block(2,0,colour) };
        break;
    case TetrominoType::O:
        colour = Colour::Yellow;
        blocks = { Block(0,0,colour), Block(1,0,colour), Block(0,1,colour), Block(1,1,colour) };
        break;
    case TetrominoType::T:
        colour = Colour::Purple;
        blocks = { Block(-1,0,colour), Block(0,0,colour), Block(1,0,colour), Block(0,1,colour) };
        break;
    case TetrominoType::S:
        colour = Colour::Green;
        blocks = { Block(0,0,colour), Block(1,0,colour), Block(-1,1,colour), Block(0,1,colour) };
        break;
    case TetrominoType::Z:
        colour = Colour::Red;
        blocks = { Block(-1,0,colour), Block(0,0,colour), Block(0,1,colour), Block(1,1,colour) };
        break;
    case TetrominoType::L:
        colour = Colour::Orange;
        blocks = { Block(-1,0,colour), Block(0,0,colour), Block(1,0,colour), Block(1,1,colour) };
        break;
    case TetrominoType::J:
        colour = Colour::Blue;
        blocks = { Block(-1,1,colour), Block(-1,0,colour), Block(0,0,colour), Block(1,0,colour) };
        break;
    }

    return Tetromino(colour, blocks, pivot, startX, startY);
}

Tetromino TetrominoFactory::createRandom() {
    int randomIndex = rand() % 7;
    TetrominoType type = static_cast<TetrominoType>(randomIndex);
    return create(type);
}
