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
	Block(int x, int y, Colour colour);
	int getXCoord();
	void setXCoord(int x);
	int getYCoord();
	void setYCoord(int y);

};

