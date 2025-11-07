#pragma once
#include <string>
#include "ColourType.h"

class Block
{
private:
	int xCoord;
	int yCoord;
	Colour colour;

public:
	Block();
	Block(int x, int y, Colour colour);
	int getXCoord() const;
	void setXCoord(int x);
	int getYCoord() const;
	void setYCoord(int y);

};

