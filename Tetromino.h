#pragma once
#include <array>
#include <utility>
#include "Block.h"

class Tetromino{
private:
	Colour colour;
	std::array<Block, 4> blocks;
	std::pair <int, int> pivot;
	int x, y;

public:
	Tetromino();
	Tetromino(Colour colour, std::array<Block, 4> blocks, std::pair <int, int> pivot, int x, int y);
	Colour getColour() const;
	void move(int dx, int dy);
	void rotateClockwise();
	void rotateCounterClockwise();
	std::array<std::pair<int, int>, 4> getGlobalCoords() const;
};

