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
    sf::Font font;
    sf::Text text;
    const float cellSize = 30.0f;
    void drawBoard(const Board& board);
    void drawTetromino(const Tetromino& t);
    void drawNextTetromino(const GameEngine& engine);
    void drawGUI(const GameEngine& engine);
    void drawGameOverScreen();
    sf::Color convertColour(Colour c);

public:
    explicit Renderer(sf::RenderWindow& w);
    void render(const GameEngine& engine);
};

