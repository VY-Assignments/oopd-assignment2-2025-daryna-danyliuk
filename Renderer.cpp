#include "Renderer.h"
#include "GameEngine.h"
#include "GameOverState.h"
#include "ScoreManager.h"
#include <iostream>

Renderer::Renderer(sf::RenderWindow& w)
    : window(w)
{
    if (!font.loadFromFile("assets/fonts/PixelifySans-VariableFont_wght.ttf")) {
        std::cout << "Error loading font PixelifySans.ttf" << std::endl;
    }
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);
}

void Renderer::render(const GameEngine& engine)
{
    window.clear(sf::Color::Black);
    drawBoard(engine.getBoard());
    drawTetromino(engine.getCurrentTetromino());
    drawGUI(engine);

    if (dynamic_cast<GameOverState*>(engine.getCurrentState())) {
        drawGameOverScreen();
    }

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

void Renderer::drawGUI(const GameEngine& engine)
{
    float baseX = engine.getBoard().getWidth() * cellSize + 90;
    float baseY = 80;

    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);

    text.setString("YOUR SCORE:");
    text.setPosition(baseX, baseY);
    window.draw(text);

    text.setString(std::to_string(engine.getScoreManager().getScore()));
    text.setPosition(baseX, baseY + 30);
    window.draw(text);

    text.setString("LINES DESTROYED::");
    text.setPosition(baseX, baseY + 80);
    window.draw(text);

    text.setString(std::to_string(engine.getScoreManager().getLinesCleared()));
    text.setPosition(baseX, baseY + 110);
    window.draw(text);

    text.setString("NEXT FIGHTER:");
    text.setPosition(baseX, baseY + 170);
    window.draw(text);

    drawNextTetromino(engine);
}

void Renderer::drawNextTetromino(const GameEngine& engine)
{
    const Tetromino& t = engine.getNextTetromino();
    auto coords = t.getGlobalCoords();
    Colour c = t.getColour();

    float offsetX = engine.getBoard().getWidth() * cellSize + 90;
    float offsetY = 270;

    for (const auto& p : coords)
    {
        sf::RectangleShape rect(sf::Vector2f(cellSize - 2, cellSize - 2));
        rect.setPosition(offsetX + (p.first - 4) * cellSize,
            offsetY + (p.second + 1) * cellSize);
        rect.setFillColor(convertColour(c));
        window.draw(rect);
    }
}
void Renderer::drawGameOverScreen()
{
    sf::RectangleShape overlay(sf::Vector2f(window.getSize().x, window.getSize().y));
    overlay.setFillColor(sf::Color(0, 0, 0, 180));
    window.draw(overlay);

    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Red);
    text.setOutlineThickness(3);
    text.setOutlineColor(sf::Color(50, 0, 0));
    text.setString("GAME OVER");

    sf::FloatRect bounds = text.getLocalBounds();
    float x = (window.getSize().x - bounds.width) / 2.f;
    float y = (window.getSize().y - bounds.height) / 2.f - 40.f;
    text.setPosition(x, y);
    window.draw(text);

    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(0);
    text.setString("Press SPACE to restart");

    sf::FloatRect restartBounds = text.getLocalBounds();
    float rx = (window.getSize().x - restartBounds.width) / 2.f;
    float ry = (window.getSize().y - restartBounds.height) / 2.f + 20.f;
    text.setPosition(rx, ry);
    window.draw(text);
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
