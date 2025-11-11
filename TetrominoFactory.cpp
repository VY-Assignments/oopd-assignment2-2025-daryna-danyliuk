#include "TetrominoFactory.h"

Tetromino TetrominoFactory::create(TetrominoType type) {
    std::array<Block, 4> blocks;
    Colour colour;
    std::pair<float, float> pivot = { 0, 0 };
    int boardX = 5;
    int boardY = 0;

    switch (type) {
    case TetrominoType::I:
        colour = Colour::Cyan;
        pivot = {0.5f, 0.5f};
        blocks = {
            Block(-1.5f,0.0f,colour), 
            Block(-0.5f,0.0f,colour), 
            Block(0.5f,0.0f,colour), 
            Block(1.5f,0.0f,colour) 
        };
        break;
    case TetrominoType::O:
        colour = Colour::Yellow;
        pivot = {0.5f, 0.5f};
        blocks = {
            Block(0.0f,0.0f,colour), 
            Block(1.0f,0.0f,colour), 
            Block(0.0f,1.0f,colour), 
            Block(1.0f,1.0f,colour) 
        };
        break;
    case TetrominoType::T:
        colour = Colour::Purple;
        pivot = {0.0f, 0.0f};
        blocks = { 
            Block(-1.0f,0.0f,colour), 
            Block(0.0f,0.0f,colour), 
            Block(1.0f,0.0f,colour), 
            Block(0.0f,1.0f,colour) 
        };       
        break;
    case TetrominoType::S:
        colour = Colour::Green;
        pivot = {0.0f, 0.0f};
        blocks = { 
            Block(0.0f,0.0f,colour), 
            Block(1.0f,0.0f,colour), 
            Block(-1.0f,1.0f,colour), 
            Block(0.0f,1.0f,colour) 
        };
        break;
    case TetrominoType::Z:
        colour = Colour::Red;
        pivot = {0.0f, 0.0f};
        blocks = { 
            Block(-1.0f,0.0f,colour), 
            Block(0.0f,0.0f,colour), 
            Block(0.0f,1.0f,colour), 
            Block(1.0f,1.0f,colour) 
        };
        break;
    case TetrominoType::L:
        colour = Colour::Orange;
        pivot = {0.0f, 0.0f};
        blocks = { 
            Block(-1.0f,0.0f,colour), 
            Block(0.0f,0.0f,colour), 
            Block(1.0f,0.0f,colour), 
            Block(1.0f,1.0f,colour) 
        };
        break;
    case TetrominoType::J:
        colour = Colour::Blue;
        pivot = {0.0f, 0.0f};
        blocks = { 
            Block(-1.0f,1.0f,colour), 
            Block(-1.0f,0.0f,colour), 
            Block(0.0f,0.0f,colour), 
            Block(1.0f,0.0f,colour) 
        };
        break;
    default:
        colour = Colour::None;
        break;
    }
    return Tetromino(colour, blocks, pivot, boardX, boardY);
}

Tetromino TetrominoFactory::createRandom() {
    int randomIndex = rand() % 7;
    TetrominoType type = static_cast<TetrominoType>(randomIndex);
    return create(type);
}
