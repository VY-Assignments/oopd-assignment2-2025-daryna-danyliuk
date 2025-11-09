#include "Tetromino.h"

Tetromino::Tetromino()
	: colour(Colour::None), localBlocks(), localPivot({ 0, 0 }), globalX(0), globalY(0)
{
}

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
	for (int i = 0; i < BLOCKS_NUM; ++i) {
		Block& block = localBlocks[i];
		float rotatedX = localPivot.first + (block.getLocalY() - localPivot.second);
		float rotatedY = localPivot.second - (block.getLocalX() - localPivot.first);
		block.setLocalX(rotatedX);
		block.setLocalY(rotatedY);
	}
}
void Tetromino::rotateCounterClockwise() {
	for (int i = 0; i < BLOCKS_NUM; ++i) {
		Block& block = localBlocks[i];
		float rotatedX = localPivot.first - (block.getLocalY() - localPivot.second);
		float rotatedY = localPivot.second + (block.getLocalX() - localPivot.first);
		block.setLocalX(rotatedX);
		block.setLocalY(rotatedY);
	}
	
}
std::array<std::pair<int, int>, BLOCKS_NUM> Tetromino::getGlobalCoords() const {
	std::array<std::pair<int, int>, BLOCKS_NUM> coords;
	for (int i = 0; i < BLOCKS_NUM; ++i) {
		const Block& block = localBlocks[i];
		int globalBlockX = globalX + (block.getLocalX() - localPivot.first);
		int globalBlockY = globalY + (block.getLocalY() - localPivot.second);
		coords[i] = {globalBlockX, globalBlockY};
	}
	return coords;
}