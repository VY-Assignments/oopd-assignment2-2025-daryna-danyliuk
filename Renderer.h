#pragma once
#include <SFML/Graphics.hpp>
#include "PlayingState.h"
#include "ColourType.h"

class GameEngine;

class Renderer
{
private:
    sf::RenderWindow& window;
    const float cellSize = 30.0f;
    void drawBoard(const Board& board);
    void drawTetromino(const Tetromino& t);
    sf::Color convertColour(Colour c);

public:
    Renderer();
    explicit Renderer(sf::RenderWindow& w);
    void render(const GameEngine& engine);
};

