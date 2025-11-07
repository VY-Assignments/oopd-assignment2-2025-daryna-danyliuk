#pragma once
#include <string>
#include <vector>
#include "ColourType.h"
#include "Tetromino.h"

class Board
{
private:
	int height;
	int width;
	std::vector<std::vector<Colour>> grid;

public:
	Board();
	bool isInside(int x, int y);
	bool isOccupied(int x, int y);
	void placeTetromino(const Tetromino&);
	void clearFullLines();
};
