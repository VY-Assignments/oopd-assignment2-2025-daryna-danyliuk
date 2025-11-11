#pragma once
#include <string>
#include "ColourType.h"

class Block
{
private:
	float localX;
	float localY;
	Colour colour;

public:
	Block();
	Block(float x, float y, Colour colour);
	float getLocalX() const;
	void setLocalX(float x);
	float getLocalY() const;
	void setLocalY(float y);
	Colour getColour();

};

