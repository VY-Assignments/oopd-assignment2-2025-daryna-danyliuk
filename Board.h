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
	Colour getCell(int x, int y) const;
	bool isInside(int x, int y) const;
	bool isOccupied(int x, int y) const;
	void placeTetromino(const Tetromino&);
	void clearFullLines();
	void clear();
	int getHeight() const;
	int getWidth() const;
};
