#pragma once
#include <string>
#include "ColourType.h"

class Block
{
private:
	int localX;
	int localY;
	Colour colour;

public:
	Block();
	Block(int x, int y, Colour colour);
	int getLocalX() const;
	void setLocalX(int x);
	int getLocalY() const;
	void setLocalY(int y);
	Colour getColour();

};

