#pragma once
#include <string>
#include <vector>
#include "ColourType.h"

class Tetromino;

class Board
{
private:
	int height = 20;
	int width = 10;
	std::vector<std::vector<Colour>> grid;

public:
	Board();
	Colour getCell(int x, int y) const {
		return grid[y][x];
	}
	bool isInside(int x, int y) const;
	bool isOccupied(int x, int y) const;
	void placeTetromino(const Tetromino&);
	void clearFullLines();
	int getHeight() const { return height; }
	int getWidth() const { return width; }
};
