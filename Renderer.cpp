#include "Renderer.h"
#include "GameEngine.h"


Renderer::Renderer(sf::RenderWindow& w)
    : window(w)
{
}

void Renderer::render(const GameEngine& engine)
{
    window.clear(sf::Color::Black);
    drawBoard(engine.getBoard());
    drawTetromino(engine.getCurrentTetromino());

    window.display();
}

void Renderer::drawBoard(const Board& board)
{
    for (int y = 0; y < board.getHeight(); ++y)
    {
        for (int x = 0; x < board.getWidth(); ++x)
        {
            Colour c = board.getCell(x, y);
            if (c != Colour::None)
            {
                sf::RectangleShape rect(sf::Vector2f(cellSize - 1, cellSize - 1));
                rect.setPosition(x * cellSize, y * cellSize);
                rect.setFillColor(convertColour(c));
                window.draw(rect);
            }
        }
    }
}

void Renderer::drawTetromino(const Tetromino& t)
{
    auto coords = t.getGlobalCoords();
    Colour c = t.getColour();

    for (const auto& p : coords)
    {       
        int x = p.first;
        int y = p.second;

        sf::RectangleShape rect(sf::Vector2f(cellSize - 1, cellSize - 1));
        rect.setPosition(x * cellSize, y * cellSize);
        rect.setFillColor(convertColour(c));
        window.draw(rect);
    }

}

sf::Color Renderer::convertColour(Colour c)
{
    switch (c)
    {
    case Colour::Red: 
        return sf::Color::Red;
    case Colour::Green: 
        return sf::Color::Green;
    case Colour::Blue: 
        return sf::Color::Blue;
    case Colour::Cyan: 
        return sf::Color::Cyan;
    case Colour::Yellow: 
        return sf::Color::Yellow;
    case Colour::Orange: 
        return sf::Color(255, 165, 0);
    case Colour::Purple:
        return sf::Color(128, 0, 128);
    default: return sf::Color::Black;
    }
}
