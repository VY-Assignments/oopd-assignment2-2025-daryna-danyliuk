#include "Tetromino.h"

std::string Tetromino::getColour() {
	return colour;
}
void Tetromino::move(int dx, int dy) {
	for (int i = 0 ; i < blocks.size(); i++) {
		int xCoord = blocks[i].getXCoord();
		int yCoord = blocks[i].getYCoord();
		int movedXCoord = xCoord + dx;
		int movedYCoord = yCoord + dy;
		blocks[i].setXCoord(movedXCoord);
		blocks[i].setYCoord(movedYCoord);
	}
}
void Tetromino::rotateClockwise() {

}
void Tetromino::rotateCounterClockwise() {
}

std::array<std::pair<int, int>, 4> Tetromino::getGlobalCoords() {
	std::array<std::pair<int, int>, 4> coords;
	for (int i = 0; i < blocks.size(); i++) {
		coords[i] = {  blocks[i].getXCoord(), blocks[i].getYCoord() };
	}
	return coords;
}