#pragma once
#include <array>
#include <utility>
#include "Block.h"

class Tetromino{
private:
	std::string colour;
	std::array<Block, 4> blocks;
	std::pair <int, int> pivot;
	int x, y;

public:
	std::string getColour();
	void move(int dx, int dy);
	void rotateClockwise();
	void rotateCounterClockwise();
	std::array<std::pair<int, int>, 4> getGlobalCoords();
};

