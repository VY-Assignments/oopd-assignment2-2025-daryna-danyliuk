#include "Board.h"

Board::Board()
{
    grid = std::vector<std::vector<Colour>>(height, std::vector<Colour>(width, Colour::None));
}
bool Board:: isInside(int x, int y) {
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		return true;
	}
	else
		return false;
}

bool Board::isOccupied(int x, int y)
{
    if (!isInside(x, y))
        return true;
    return grid[y][x] != Colour::None;
}
void Board::placeTetromino(const Tetromino& t)
{
    auto coords = t.getGlobalCoords();
    Colour colour = t.getColour();

    for (auto [x, y] : coords)
    {
        if (isInside(x, y))
        {
            grid[y][x] = colour;
        }
    }
}
void Board::clearFullLines()
{
    for (int y = height - 1; y >= 0; --y)
    {
        bool full = true;

        for (int x = 0; x < width; ++x)
        {
            if (grid[y][x] == Colour::None)
            {
                full = false;
                break;
            }
        }
        if (full)
        {
            grid.erase(grid.begin() + y);
            grid.insert(grid.begin(), std::vector<Colour>(width, Colour::None));
            y++; 
        }
    }
}
void Board::clearFullLines() {

}