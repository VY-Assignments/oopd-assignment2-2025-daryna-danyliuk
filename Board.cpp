#include "Board.h"
#include "Tetromino.h"
#include <array> 
#include <utility> 

Board::Board()
{
    grid = std::vector<std::vector<Colour>>(height, std::vector<Colour>(width, Colour::None));
}

Colour Board::getCell(int x, int y) const {
    return grid[y][x];
}

bool Board::isInside(int x, int y) const 
{
    return (x >= 0 && x < width && y >= 0 && y < height);
}
int Board ::  getHeight() const { 
    return height; 
}

int Board :: getWidth() const { 
    return width; 
}
bool Board::isOccupied(int x, int y) const
{
    if (!isInside(x, y))
        return true;
    return grid[y][x] != Colour::None;
}

void Board::placeTetromino(const Tetromino& t)
{
    auto coords = t.getGlobalCoords();
    Colour colour = t.getColour();
    for (const auto& coord : coords)
    {
        int x = coord.first;
        int y = coord.second;
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
void Board::clear() {
    for (auto& row : grid)
        std::fill(row.begin(), row.end(), Colour::None);
}