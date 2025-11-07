#include "PlayingState.h"
#include "GameEngine.h"
#include "Board.h"
#include "Tetromino.h"

PlayingState::PlayingState()
    : fallTimer(0.0f), fallInterval(0.5f)
{
}

void PlayingState::update(GameEngine& engine, float deltaTime) {
    fallTimer += deltaTime;

    if (fallTimer >= fallInterval) {
        Tetromino& current = engine.getCurrentTetrominoRef();
        current.move(0, 1);
        auto coords = current.getGlobalCoords();
        bool collision = false;

        for (const auto& coord : coords)
        {
            int x = coord.first;
            int y = coord.second;
            if (!engine.getBoard().isInside(x, y) || engine.getBoard().isOccupied(x, y)) {
                collision = true;
                break;
            }
        }

        if (collision) {
            current.move(0, -1);
            engine.getBoardRef().placeTetromino(current);
            engine.getBoardRef().clearFullLines();
            Tetromino next = engine.getFactory().createRandom();
            engine.setCurrentTetromino(next);
        }
        fallTimer = 0.0f;
    }
}

void PlayingState::handleInput(GameEngine& engine) {
}

void PlayingState::onEnter() {
}

void PlayingState::onExit() {
}