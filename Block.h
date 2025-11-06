#pragma once
#include <string>

class Block
{
private:
	int xCoord;
	int yCoord;
	std::string colour;

public:
	Block(int x, int y, std::string colour);
	int getXCoord();
	void setXCoord(int x);
	int getYCoord();
	void setYCoord(int y);

};

