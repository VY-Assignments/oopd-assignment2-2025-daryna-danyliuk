#pragma once
#include "Board.h"
#include "Tetromino.h"
#include <SFML/Graphics.hpp>
#include "PlayingState.h"
#include "ColourType.h"
#include "Board.h"
#include "Tetromino.h"


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
    explicit Renderer(sf::RenderWindow& w);
    void render(const GameEngine& engine);
};

