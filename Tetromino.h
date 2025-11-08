#pragma once
#include <array>
#include <utility>
#include "Block.h"
const int BLOCKS_NUM = 4;

class Tetromino{
private:
	Colour colour;
	std::array<Block, BLOCKS_NUM> localBlocks;
	std::pair <int, int> localPivot;
	int globalX, globalY;

public:
	Tetromino();
	Tetromino(Colour colour, std::array<Block, BLOCKS_NUM> localBlocks, std::pair <int, int> localPivot, int globalX, int globalY);
	Colour getColour() const;
	void move(int dx, int dy);
	void rotateClockwise();
	void rotateCounterClockwise();
	std::array<std::pair<int, int>, BLOCKS_NUM> getGlobalCoords() const;
};

