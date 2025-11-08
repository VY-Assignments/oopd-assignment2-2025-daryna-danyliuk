#include "Tetromino.h"


Tetromino::Tetromino(Colour colour, std::array<Block, BLOCKS_NUM> blocks, std::pair<int, int> pivot, int x, int y)
	: colour(colour), localBlocks(blocks), localPivot(pivot), globalX(x), globalY(y)
{
}

Colour Tetromino::getColour() const {
	return colour;
}
void Tetromino::move(int dx, int dy) {
	globalX += dx;
	globalY += dy;
}
void Tetromino::rotateClockwise() {

}
void Tetromino::rotateCounterClockwise() {
}
std::array<std::pair<int, int>, BLOCKS_NUM> Tetromino::getGlobalCoords() const {
	std::array<std::pair<int, int>, BLOCKS_NUM> coords;
	for (int i = 0; i < BLOCKS_NUM; ++i) {
		const Block& block = localBlocks[i];
		int globalBlockX = globalX + (block.getLocalX() - localPivot.first);
		int globalBlockY = globalY + (block.getLocalY() - localPivot.second);
		coords[i] = { globalBlockX, globalBlockY };
	}
	return coords;
}